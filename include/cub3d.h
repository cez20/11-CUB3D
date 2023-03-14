/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:37:31 by anarodri          #+#    #+#             */
/*   Updated: 2023/03/14 15:37:32 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include "../include/libft/libft.h"

# define ERR_ARGS "Error: There is NO arguments or more than 1 argument!\n"
# define ERR_FD "Error: Couldn't open file. Check if it exists, it's valid\
 and you have the right permissions.\n"
# define ERR_EXT "Error: Map does not have the right extension (.cub).\n"
# define ERR_DIR "Error: Do you know the difference between a file and a directory? \
You should.\n"
# define ERR_EMPTY_MAP "Error: Map is empty!\n"
# define ERR_WRONG_ELEMENT "Error: Invalid game element is present. \
 Valid elements: NO, SO, WE, EA, F and C.\n"
# define ERR_MISSING_ELEMENT "Error: One (or more) mandatory element is missing.\
 Check if NO, SO, WE, EA, F and C are all present!\n"
# define ERR_EXTRA_ELEMENT "Error: One (or more) argument in the map details is duplicated.\
 Check texture's paths and floor/ceiling colors.\n"
# define ERR_TOOMUCH_TEXT "Error: There is extra text after texture path!\n"
# define ERR_TEXTURE_PATH "Error: There is an error in texture path.\n"
# define ERR_PLAYER "Error: NO player found or TOO MANY players.\
 Must have only ONE player.\n"
# define ERR_RGB "Error: Invalid RGB value. You must have only three integers\
 and all its values should be between 0 and 255.\n"
# define ERR_CHAR "Error: Undefined (invalid) character on map.\
 Valid characters: N, S, E, W, 0 and 1.\n"
# define ERR_INTEGRITY "Error: Map must be surrounded by walls and have no uncontained\
 spaces inside its limits.\n"
# define ERR_XPM42 "Error: Problem while loading xpm42 image.\n"

# define WIDTH 960
# define HEIGHT 600
# define EAST 0
# define WEST 1
# define SOUTH 2
# define NORTH 3

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
	int				player_x;
	int				player_y;
	char			direction;
	char			**game_copy;
	char			**map_copy;
	char			**elements_copy;	
	mlx_t			*mlx;
	mlx_image_t		*game;
	t_tex			*tex;
	t_ray			*rc;
}					t_game;

typedef struct s_tex
{
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	int				**n;
	int				**s;
	int				**e;
	int				**w;
	xpm_t			*no;
	xpm_t			*so;
	xpm_t			*ea;
	xpm_t			*we;
	int				ceiling[3];
	int				floor[3];
	int				texture_x;
	int				texture_y;
	int				texture_num;
}					t_tex;

typedef struct s_ray
{
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	char			**map;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			ray_dir_x;
	double			ray_dir_y;
	double			delta_dis_x;
	double			delta_dis_y;
	double			side_dis_x;
	double			side_dis_y;
	double			camera_x;
	double			move_speed;
	double			rot_speed;
	double			intersect_dist;
	uint32_t		ceiling;
	uint32_t		floor;
}					t_ray;

//********************************************************
//* 				ENGINE FOLDER 						 *
//********************************************************
//*** DRAW_GAME.C ***
void		floor_n_ceiling(t_game *g);
void		draw_texture_line(t_game *g, xpm_t *tex, int **tab, int i);

//*** MOVE.C ***
void		look_right(t_ray *rc);
void		look_left(t_ray *rc);
void		strafe(t_ray *rc, char dir);
void		forward(t_ray *rc);
void		backward(t_ray *rc);

//*** RAYCASTER.C ***
void		raycaster(t_game *g);

//*** TEXTURE.C ***
void		texture_calculation(t_game *g);
void		load_and_convert_textures(t_game *g);

//*** UTILS.C ***
int			init_mlx_variables(t_game *g);
void		init_dda_variables(t_game *g);

//********************************************************
//* 				MAIN FOLDER 						 *
//********************************************************

//*** CUB3D.C ***
int			cub3d(t_game *g);
void		keybinding(mlx_key_data_t input, void *tmp);

//*** MAIN.C ***
void		init_variables(t_game *game);
int			main(int argc, char **argv);

//********************************************************
//* 				PARSING FOLDER						 *
//********************************************************

//*** ELEMENTS_PARSING.C ***
void		check_colors(t_game *game, char *element, int *area);
char		*create_texture_path(t_game *game, char *path);
void		check_direction(t_game *game, char *str, char **texture_path);
void		verify_elements(t_game *game);

//*** ELEMENTS_UTILS.C ***
u_int32_t	get_color(int r, int g, int b, int a);
int			is_floor_or_ceiling(char *str);
int			nb_of_strings(char **str);
int			ft_is_whitespace(char c);

//*** GAME_PARSING.C ***
void		game_parsing(t_game *game);
void		game_validation(t_game *game, int argc, char *argv);

//*** GAME_SECTIONS_COPY.C ***
void		game_map_copy(t_game *game);
void		game_elements_copy(t_game *game);
void		game_map_dimensions(t_game *game);
void		game_full_copy(t_game *game, char *argv);
void		game_sections_copy(t_game *game, char *argv);

//*** GAME_SECTIONS_UTILS.C ***
int			map_longest_width(t_game *game);
int			map_first_index(char **game);
void		game_length(t_game *game);
void		ft_strlcpy1(char *dst, const char *src, size_t size);

//*** MAP_PARSING.C ***
void		replace_map_spaces(t_game *game);
void		verify_map_walls(t_game *game);
void		verify_map_characters(t_game *g);

//*** MAP_UTILS.C ***
int			is_news(char c);
int			is_wall(char c);
void		player_position(t_game *game, int x, int y);
void		skip_whitespaces(char **str);

//********************************************************
//* 				UTILS FOLDER						 *
//********************************************************

//*** ERROR.C ***
void		errmsg(char *msg, int tofree, t_game *game);

//*** FREE.C ***
void		free_game(t_game *game);
void		free_double_pointer(char **str);
void		close_fds(t_game *game);

//*** PRINT_UTILS.C ***
void		print_variables(t_game *game);
void		print_game(char **map);

#endif