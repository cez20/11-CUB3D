#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../include/libft/libft.h"
# include "../include/libft/GNL/get_next_line.h"

# define ERR_ARGS "There is NO arguments or more than 1 argument!\n"
# define ERR_NO_MAP "Map given does not exist!\n"
# define ERR_EXT "Map has NO extension or extension different than '.cub'!\n"
# define ERR_EMPTY_MAP "Map is empty!\n"
# define ERR_CONTENT "Map: Invalid character, NO player or TOO MANY players\n"

// typedef struct s_img
// {
// 	void	*img;
// 	char	*addr;
// 	int		bpp;
// 	int		line_length;
// 	int		endian;
// 	int		width;
// 	int		height;
// }			t_img;

typedef struct s_game
{
	int		fd;
	int		total_length;
	int		map_index;
	// int		player_x;
	// int		player_y;
	char	**game_copy;
	char	**map_copy;
	char	**elements_copy;
	void	*mlx;
	void	*window;
}				t_game;

//*** MAIN.C ***
int		main(int argc, char **argv);

//*** ERROR.C ***
void	error(char *str);

//*** FREE.C ***
void	free_game(t_game *game);
void	free_double_pointer(char **str);

//*** GAME_VALIDATION.C ***
void	game_valid_extension(char *str, int fd);
void	game_full_copy(t_game *game, char *argv);
void	game_length(t_game *game);
void	game_map_copy(t_game *game);
void	game_elements_copy(t_game *game);
void	game_copy(t_game *game, char *argv);

//*** GAME_VALIDATION1.C ***
int		is_valid_character(char c);
void	game_map_content(t_game *game);
void	game_content_validation(t_game *game);

//*** PRINT_UTILS.C ***
void	print_variables(t_game *game);
void	print_game(char **game);
//void	print_full_game(t_game *game);

#endif