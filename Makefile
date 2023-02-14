NAME	=	cub3d

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g

#INCLUDE	= ./libft/libft.a
INCLUDE	=	-framework OpenGL -framework AppKit ./include/libft/libft.a ./include/MLX42/libmlx42.a

RM		=	@rm -rf

#----------FOLDER PATHS----------#
INC_DIR		=	include/
LIBFT_DIR	=	$(INC_DIR)libft/
LIBFT_H		=	$(LIBFT_DIR)libft.h
MLX_DIR 	=	$(INC_DIR)MLX42/

SRC_DIR				=	src/
MAIN_DIR			=	$(SRC_DIR)main/
ENGINE_DIR			=	$(SRC_DIR)engine/
PARSING_DIR			=	$(SRC_DIR)parsing/

OBJ_DIR		=	obj/

#----------FILES----------#

MAIN_F	=		\
main.c			\
error.c			\
game_validation.c	\
game_validation1.c  \
print_utils.c		\
free.c 			\

ENGINE_F	=	\
#files.c

PARSING_F =		\
#files.c


#----------ADDPREFIX TO FILES----------#
MAIN_SRC	=	$(addprefix $(MAIN_DIR), $(MAIN_F))
ENGINE_SRC	=	$(addprefix $(ENGINE_DIR), $(ENGINE_F))
PARSING_SRC	=	$(addprefix $(PARSING_DIR), $(PARSING_F))

OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
OBJ_FILES	=	$(MAIN_F:.c=.o) $(ENGINE_F:.c=.o) $(PARSING_F:.c=.o)

VPATH		=	$(SRC_DIR) $(MAIN_DIR) $(ENGINE_DIR) $(PARSING_DIR) $(LIBFT_H)

$(OBJ_DIR)%.o: %.c $(SRC_DIR)
			$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

#----------RECIPES----------#
all:		obj $(NAME)

$(NAME):	$(OBJ_DIR) $(OBJS)
			@echo "\033[1;32mCompiling libft...\033[0m"
			@make --silent -C $(LIBFT_DIR)
			@echo "\033[1;32mDone\n\033[0m"
			@echo "\033[1;32mCompiling MLX42...\033[0m"
			@make --silent -C $(MLX_DIR)
			@echo "\033[1;32m\nCompiling $(NAME)...\033[0m"
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)libft.a $(MLX_DIR)libmlx42.a -o $(NAME)
			@echo "\033[1;32mDone\033[0m"

obj:
			@mkdir -p $(OBJ_DIR)

leak:		obj $(NAME)
			@valgrind --leak-check=full --show-leak-kinds=all ./cub3d

clean:
			@echo "Removing object files..."
			@$(RM) $(OBJ_DIR)
			@make -C $(LIBFT_DIR) clean
			@make -C $(MLX_DIR) clean
			@echo "\033[1;32mDone\033[0m"

fclean:		clean
			@echo "Removing $(NAME)..."
			@$(RM) $(NAME)
			@$(RM) $(NAME).dSYM*
			@make -C $(LIBFT_DIR) fclean
			@make -C $(MLX_DIR) fclean
			@echo "\033[1;32mDone\033[0m"

re:			fclean all

test:
			./test.sh

norm:
			norminette $(SRC) *.h */*.h

.PHONY:		all clean fclean re test norm