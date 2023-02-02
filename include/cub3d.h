#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h> // For open() function; 
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define ERR_ARGS "There is NO arguments or more than 1 argument\n"
# define ERR_FD "FD(map) given does not exist!\n"
# define ERR_EXT "Map does not have extension '.ber'!\n"


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
	char	**map;
	int		width;
	int		height;
	int		players;
	void	*mlx;
	void	*window;
	int		player_x;
	int		player_y;
}				t_game;

//*** MAIN.C ***
int		main(int argc, char **argv);

//*** ERROR.C ***
void	error(char *str);

#endif