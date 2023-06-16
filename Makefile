NAME	=	cub3D

CC		=	gcc

RM		=	@rm -rf

#----------FLAGS----------#
#INCLUDE	= ./libft/libft.a
CFLAGS	=	-Wall -Werror -Wextra -g -w #Added -w to remove the warnings 
INCLUDE	=	-framework OpenGL -framework AppKit -framework Cocoa -framework IOKit ./include/libft/libft.a ./include/MLX42/libmlx42.a
LIB_FLAG= 	-L./include/libft -lft
MLX_FLAGS =	-L./include/glfw/build/src/ -lglfw3

#----------FOLDER PATHS----------#
INC_DIR		=	include/
LIBFT_DIR	=	$(INC_DIR)libft/
LIBFT_H		=	$(LIBFT_DIR)libft.h
MLX_DIR 	=	$(INC_DIR)MLX42/

SRC_DIR				=	src/
MAIN_DIR			=	$(SRC_DIR)main/
ENGINE_DIR			=	$(SRC_DIR)engine/
PARSING_DIR			=	$(SRC_DIR)parsing/
UTILS_DIR			=	$(SRC_DIR)utils/

OBJ_DIR		=	obj/

#----------FILES----------#
ENGINE_F	=		\
draw_game.c			\
move.c				\
raycaster.c			\
texture.c 			\
utils.c				\

MAIN_F	=			\
cub3d.c				\
main.c				\


PARSING_F =			\
elements_parsing.c	\
elements_utils.c	\
game_parsing.c		\
game_sections_copy.c\
game_sections_utils.c\
map_parsing.c 		\
map_utils.c			\

UTILS_F =			\
error.c				\
free.c				\
print_utils.c		\


#----------ADDPREFIX TO FILES----------#
MAIN_SRC	=	$(addprefix $(MAIN_DIR), $(MAIN_F))
ENGINE_SRC	=	$(addprefix $(ENGINE_DIR), $(ENGINE_F))
PARSING_SRC	=	$(addprefix $(PARSING_DIR), $(PARSING_F))
UTILS_SRC	=	$(addprefix $(UTILS_DIR), $(UTILS_F))

OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
OBJ_FILES	=	$(MAIN_F:.c=.o) $(ENGINE_F:.c=.o) $(PARSING_F:.c=.o) $(UTILS_F:.c=.o)

VPATH		=	$(SRC_DIR) $(MAIN_DIR) $(ENGINE_DIR) $(PARSING_DIR) $(UTILS_DIR) $(LIBFT_H)

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
			$(CC) $(CFLAGS) $(OBJS) -Iinclude/ -o $(NAME) $(INCLUDE) $(LIB_FLAG) $(MLX_FLAGS)
			@echo "\033[1;32mDone\033[0m"

obj:
			@mkdir -p $(OBJ_DIR)

leak:		obj $(NAME)
#			@valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./cub3d ./mapfiles/pdf_minimal.cub
			@leaks --atExit -- ./cub3d mapfiles/pdf_minimal.cub
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