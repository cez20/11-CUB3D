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
# define ERR_MAP_WALLS "Map is not surrounded by walls!\n"
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
	int				fd;
	int				total_length;
	int				map_index;
	int				map_width;
	int				map_height;
	int				nb_player;
	int				player_x;
	int				player_y;
	//int				error; // voir si encore necessaire 
	char			**game_copy;
	char			**map_copy;
	char			**map_copy1;
	char			**elements_copy;
	void			*mlx;
	void			*window;
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

//*** MAP_UTILS.C ***
void	map_to_table(int fd, t_game *game);
void	flood_fill(int x, int y, t_game *game);

//*** FREE.C ***
void	free_game(t_game *game);
void	free_double_pointer(char **str);

//*** GAME_PARSING.C ***
int		is_news(char c);
int		is_wall(char c);
void	player_position(t_game *game, int x, int y);
void	game_map_content(t_game *game);
void	game_parsing(t_game *game);

//*** GAME_PARSING1.C ***
void	flood_fill(int x, int y, t_game *game);
void	verify_corner_walls(t_game *game);
void	verify_first_last_wall(t_game *game, int i);
void	verify_vertical_walls(t_game *game, int i);
void	verify_map_walls(t_game *game);

//*** GAME_SECTIONS_COPY.C ***
void	game_map_copy(t_game *game);
void	game_elements_copy(t_game *game);
void	game_map_dimensions(t_game *game);
void	game_full_copy(t_game *game, char *argv);
void	game_sections_copy(t_game *game, char *argv);

//*** GAME_SECTIONS_COPY1.C ***
void	game_length(t_game *game);
int		map_first_index(char **game);
int		map_longest_width(t_game *game);
void	ft_strlcpy1(char *dst, const char *src, size_t size);

//*** GAME_VALIDATION.C ***
void	game_valid_extension(t_game *game, char *str);
void	game_validation(t_game *game, int argc, char *argv);

//*** PRINT_UTILS.C ***
void	print_variables(t_game *game);
void	print_game(char **map);

#endif