#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "./libft/libft.h"
# include "./libft/GNL/get_next_line.h"
# include "./MLX42/include/MLX42/MLX42.h"
//# include "./mlx_linux/mlx.h"
# include "../include/libft/libft.h"


# define ERR_ARGS "There is NO arguments or more than 1 argument!\n"
# define ERR_FD "Error: FD (map) given does not exist!\n"
# define ERR_NO_MAP "Map given does not exist!\n"
# define ERR_EXT "Error: Map does not have the right extension (.cub).\n"
# define ERR_OPEN "Error: Couldn't open file. Check if it exists, it's valid\
 and you have the right permissions.\n"
# define ERR_EMPTY_MAP "Map is empty!\n"
# define ERR_CONTENT "Map: Invalid character, NO player or TOO MANY players\n"
# define ERR_MAPDATA "Error: One or more arguments in the map details\
 is missing.\n"
# define ERR_RGB "Error: Invalid RGB value. All values should stay\
 between 0 and 255.\n"
# define ERR_CHAR "Error: Undefined (invalid) character on map.\
 Valid characters: N, S, E, W, 0 and 1.\n"
# define ERR_INTEGRITY "Error: Map must be surrounded by walls and have no spaces\
 inside its limits.\n"
# define ERR_START "Error: The map must have exactly one starting point.\n"

# define WIDTH 1920
# define HEIGHT 1080

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
	int		player_x;
	int		player_y;
	char	**game_copy;
	char	**map_copy;
	char	**elements_copy;
	void	*mlx;
	void	*window;
	int				width;
	int				height;
	struct t_tex	*tex;
	struct t_ray	*rc;
}				t_game;

typedef struct s_tex
{
// textures data
}				t_tex;

typedef struct s_ray
{
// values for raycasting math
// some must be variables of type double for precision!
}				t_ray;


//*** MAIN.C ***
int		main(int argc, char **argv);

//*** ERROR.C ***
void	error(char *str);
void	errmsg(char *msg, int tofree, t_game *game);


//*** VALIDATION.C ***
void	map_to_table(int fd, t_game *game);
void	flood_fill(int x, int y, t_game *game);
void	print_map(char **map);

//*** FREE.C ***
void	free_game(t_game *game);
void	free_double_pointer(char **str);

//*** GAME_VALIDATION.C ***
void	game_valid_extension(char *str, int fd, t_game *game);
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