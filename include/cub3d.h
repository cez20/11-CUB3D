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
	char	**full_map;
	void	*mlx;
	void	*window;
	//int		map_length;  Si on les active, mettre le contenu dans init_variables. 
	//int		elements_length;
}				t_game;

//*** MAIN.C ***
int		main(int argc, char **argv);

//*** ERROR.C ***
void	error(char *str);

//*** GAME_VALIDATION.C ***
void	game_valid_extension(char *str, int fd);
void	game_copy(t_game *game);
void	game_length(t_game *game);

//*** PRINT_UTILS.C ***
void	print_variables(t_game *game);

#endif