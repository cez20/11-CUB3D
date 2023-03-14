#include "../include/cub3d.h"

//This function essentially draws one "x-axis at a time"
// Ex: draws position (0,0) , (1, 0), (2, 0)
// Then draws 0,1 , (1, 1), (2, 1)
void	draw_background(t_game *g)
{
	int	x;
	int	y;

	y = 0; // Moves vertically
	while (y < g->map_height * 64)
	{
		x = 0; // Moves horizontally
		while (x < g->map_width * 64)
		{
			mlx_put_pixel(g->minimap, x, y, get_color(115, 147, 179, 255));
			x++;
		}
		y++;
	}
}

// static void	p_ray(t_game *g, int posx, int posy)
// {
// 	int		len;
// 	double	x;
// 	double	y;

// 	x = posx;
// 	y = posy;
// 	len = 55;
// 	while (len > 0)
// 	{
// 		mlx_put_pixel(g->minimap, x, y, 0x00FF0000);
// 		x += g->rc->dir_x;
// 		y += g->rc->dir_y;
// 		len--;
// 	}
// }

// This function draws a red square to represent the player. Given
// that X and Y represent here the position at the top left corner
// I advanced bpth the x and y of 25 to get close to the middle of
// each box.  
void	draw_player(t_game *g, int x, int y, uint32_t color)
{
	int	x_offset;
	int	y_offset;
	int	scaled_x;
	int	scaled_y;

	x_offset = 1;
	y_offset = 1;
	scaled_x = x;
	scaled_y = y;
	while (y_offset < 10)
	{
		x_offset = 1;
		while (x_offset < 10)
		{
			mlx_put_pixel(g->minimap, scaled_x, scaled_y, color);
			x_offset++;
			scaled_x++;
		}
		scaled_x = x;
		scaled_y++;
		y_offset++;
	}
}

// This function draws each elements of the map. All "1" which represents
// a wall, is painted in black and all empty area is in white.
void	draw_square(t_game *g, int x, int y, uint32_t color)
{
	int	x_offset;
	int	y_offset;
	int	scaled_x;
	int	scaled_y;

	x_offset = 1;
	y_offset = 1;
	scaled_x = x + 1;
	scaled_y = y + 1;
	while (y_offset < (64 - 1))
	{
		x_offset = 1;
		while (x_offset < (64 - 1))
		{
			mlx_put_pixel(g->minimap, scaled_x, scaled_y, color);
			x_offset++;
			scaled_x++;
		}
		scaled_x = x + 1;
		scaled_y++;
		y_offset++;
	}
}

// This functions calls up the draw square function along with the color needed
// for each square. We inverted the x and y because when we want to circulate
// horizontally on the x_axis, we are in fact moving on the y-axis 
void	draw_map(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->map_copy[y])
	{
		x = 0;
		while (g->map_copy[y][x])
		{
			if (g->map_copy[y][x] == '1')
				draw_square (g, x * 64, y * 64, get_color(0, 0, 0, 255));
			else
				draw_square (g, x * 64, y * 64, get_color(255, 255, 255, 255));
			x++;
		}
		y++;
	}
}

u_int32_t	get_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
