#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include "./libft/libft.h"
# include "./libft/GNL/get_next_line.h"
# include "./MLX42/include/MLX42/MLX42.h"
//# include "./mlx_linux/mlx.h"
# include "../include/libft/libft.h"


# define ERR_ARGS "Error: There is NO arguments or more than 1 argument!\n"
# define ERR_FD "Error: FD (map) given does not exist!\n"
# define ERR_NO_MAP "Error: Map given does not exist!\n"
# define ERR_EXT "Error: Map does not have the right extension (.cub).\n"
# define ERR_OPEN "Error: Couldn't open file. Check if it exists, it's valid\
 and you have the right permissions.\n"
# define ERR_EMPTY_MAP "Error: Map is empty!\n"
# define ERR_MAP_WALLS "Error: Map is not surrounded by walls!\n"
# define ERR_CONTENT "Error: Map: Invalid character, NO player or TOO MANY players\n"
# define ERR_MAPDATA "Error: One or more arguments in the map details\
 is missing.\n"
# define ERR_RGB "Error: Invalid RGB value. You must have only three integers\
 and all its values should be between 0 and 255.\n"
# define ERR_CHAR "Error: Undefined (invalid) character on map.\
 Valid characters: N, S, E, W, 0 and 1.\n"
# define ERR_INTEGRITY "Error: Map must be surrounded by walls and have no spaces\
 inside its limits.\n"
# define ERR_START "Error: The map must have exactly one starting point.\n"
# define ERR_ELEMENTS "Error: An invalid game element is present\n"
# define ERR_TEXTURE "Error: there is an error with path leading to texture\n"
# define ERR_EXTRA_PATH "Error: There is an extra direction (NO,SO,EA,WE) in game elements\n"

# define WIDTH 640
# define HEIGHT 480

# define WHITESPACE " \n\t\v\r\f"

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

typedef struct s_tex	t_tex;
typedef struct s_ray	t_ray;

typedef struct s_game
{
	int				fd;
	int				total_length;
	int				map_index;
	int				map_width;
	int				map_height;
	int				nb_player;
	double			player_x;
	double			player_y;
	char			**game_copy;
	char			**map_copy;
	char			**elements_copy;	
	void			*mlx;
	void			*window;
	t_tex			*tex;
	t_ray			*rc;
}				t_game;

typedef struct s_tex
{
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	xpm_t			*no;
	xpm_t			*so;
	xpm_t			*ea;
	xpm_t			*we;
	int				floor[3];
	int				ceiling[3];
}				t_tex;

typedef struct s_ray
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
}				t_ray;

//********************************************************
//* 				MAIN FOLDER 						 *
//********************************************************

//*** MAIN.C ***
void	init_variables(t_game *game);
void	close_fds(t_game *game);
int		main(int argc, char **argv);

//********************************************************
//* 				PARSING FOLDER						 *
//********************************************************

//*** ELEMENTS_PARSING.C ***
void	check_colors(t_game *game, char *element);
char	*create_texture_path(t_game *game, char *path);
void	check_direction(t_game *game, char *str, char **texture_path);
void	verify_elements(t_game *game);

//*** ELEMENTS_UTILS.C ***
int		is_floor_or_ceiling(char *str);
int		nb_of_strings(char **str);
int		ft_is_whitespace(char c);

//*** GAME_PARSING.C ***
void	game_parsing(t_game *game);
void	game_valid_extension(t_game *game, char *str);
void	game_validation(t_game *game, int argc, char *argv);

//*** GAME_SECTIONS_COPY.C ***
void	game_map_copy(t_game *game);
void	game_elements_copy(t_game *game);
void	game_map_dimensions(t_game *game);
void	game_full_copy(t_game *game, char *argv);
void	game_sections_copy(t_game *game, char *argv);

//*** GAME_SECTIONS_UTILS.C ***
int		map_longest_width(t_game *game);
int		map_first_index(char **game);
void	game_length(t_game *game);
void	ft_strlcpy1(char *dst, const char *src, size_t size);

//*** MAP_PARSING.C ***
void	replace_map_spaces(t_game *game);
void	verify_map_walls(t_game *game);
void	verify_map_characters(t_game *g);

//*** MAP_UTILS.C ***
int		is_news(char c);
int		is_wall(char c);
void	player_position(t_game *game, int x, int y);
void	skip_whitespaces(char **str);

//********************************************************
//* 				UTILS FOLDER						 *
//********************************************************

//*** ERROR.C ***
void	error(char *str);
void	errmsg(char *msg, int tofree, t_game *game);

//*** FREE.C ***
void	free_game(t_game *game);
void	free_double_pointer(char **str);

//*** PRINT_UTILS.C ***
void	print_variables(t_game *game);
void	print_game(char **map);

#endif