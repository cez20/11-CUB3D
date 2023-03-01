#include "../include/cub3d.h"

// TODO:
	// load xpm
	//	g->tex->no = mlx_load_xpm42(g->tex->north);
	// if (!g->tex->no)
	// 	errmsg("Load XPM fail.\n", 1, g);

	// code dda/raycaster
	// code keyhooks modifiers
	// draw image
	// put image to window
	// rinse repeat

// static void draw_background(t_game *g)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (y < WIDTH)
// 	{
// 		x = 0;
// 		while (x < HEIGHT)
// 		{
// 			mlx_put_pixel(g->img, y, x , get_color(115, 147, 179, 155));
// 			x++;
// 		}
// 	y++;
// 	}
// }

//This function puts a colour in all the background of the image. When
// you move your player, it avoid that the colour of the player stays in
// the division. 
static void draw_background(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (g->map_width * 64))
	{
		x = 0;
		while (x < (g->map_height * 64))
		{
			mlx_put_pixel(g->img, y, x , get_color(115, 147, 179, 155));
			x++;
		}
		y++;
	}
}

// This function draws a red square to represent the player. Given
// that X and Y represent here the position at the top left corner
// I advanced bpth the x and y of 25 to get close to the middle of
// each box.  
static void	draw_player (t_game *g, int x, int y, uint32_t color)
{
	int i;
	int j;
	int mod_x;
	int	mod_y;

	i = 25;
	j = 25;
	mod_x = x + 25;
	mod_y = y + 25;

	while (i < 40)
	{
		while (j < 40)
		{
			mlx_put_pixel(g->img, mod_x, mod_y, color);
			j++;
			mod_x++;
		}
		mod_x = x + 25;
		j = 25;
		mod_y++;
		i++;
	}
}

// This function draws each elements of the map. All "1" which represents
// a wall, is painted in black and all empty area is in white.
static void	draw_square (t_game *g, int x, int y, uint32_t color)
{
	int i;
	int j;
	int mod_x;
	int	mod_y;

	i = 1; // We start in one, so that the edge of each square in of a different colours
	j = 1;
	mod_x = x;
	mod_y = y;
	while (i < (64 - 1)) // We do minus 1 to make use that edge is of a different colour
	{
		while (j < (64 - 1))
		{
			mlx_put_pixel(g->img, mod_x, mod_y, color);
			j++;
			mod_x++;
		}
		mod_x = x;
		j = 1;
		mod_y++;
		i++;
	}
}

// This functions calls up the draw square function along with the color needed
// for each square. We inverted the x and y because when we want to circulate
// horizontally on the x_axis, we are in fact moving on the y-axis 
void draw_map(t_game *g)
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
				draw_square (g, x * 64, y * 64, get_color(0, 0, 0, 155));
			else
				draw_square (g, x * 64, y * 64, get_color(255, 255, 255, 155));
			x++;
		}
		y++;
	}
}


// This function is for events, everytime a key is pressed, we move the player position of 0.2
// to the left, to the right, up or down.To make sure that map is updated in real time,
// we call back the function draw _background, draw_map, and draw_player. If these functions,
// were not called, there would'nt be any change between first map and other maps. 
void	keybinding(mlx_key_data_t input, void *tmp)
{
	t_game	*g;

	g = tmp;
	if (input.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(g->mlx);
		return ;
	}
	// if (input.key == MLX_KEY_RIGHT && g->map_copy[(int)g->rc->pos_x][(int)g->rc->pos_y] != '1')
	// 	g->rc->pos_y += 0.2;
	if (input.key == MLX_KEY_RIGHT)
		g->rc->pos_y += 0.2;
	if (input.key == MLX_KEY_LEFT)
		g->rc->pos_y -= 0.2;
	if (input.key == MLX_KEY_UP)
		g->rc->pos_x -= 0.2;
	if (input.key == MLX_KEY_DOWN)
		g->rc->pos_x += 0.2;
	draw_background(g);
	draw_map(g);
	draw_player(g, g->rc->pos_y * 64, g->rc->pos_x * 64, get_color(255, 0, 0, 155));
}


void	rendering(t_game *g)
{
	draw_background(g); // This is the background color
	draw_map(g);
	draw_player(g, g->rc->pos_y * 64, g->rc->pos_x * 64, get_color(255, 0, 0, 155));
	mlx_image_to_window(g->mlx, g->img, 0, 0);
}

int	cub3d(t_game *g)
{
	g->mlx = mlx_init(WIDTH , HEIGHT, "Cub3d", true); // Le true authorize le resize le map, mettre la map full screen.  
	if (!g->mlx)
		return (-1);
	init_img_variables(g);
	//print_variables(g);
	rendering(g);
	mlx_key_hook(g->mlx, &keybinding, g); //duplicating?
//	mlx_cursor_hook(); // optional (bonus)
	mlx_loop(g->mlx);
	mlx_terminate(g->mlx);
	return (0);
}
