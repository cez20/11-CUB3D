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


static void	draw_player (t_game *g, int x, int y, uint32_t color)
{
	int i;
	int j;
	int mod_x;
	int	mod_y;

	i = 0;
	j = 0;
	if (x == 0)
		x = 4;
	if (y == 0)
		y = 4; // to be changed when the coodinates are scaled
	mod_x = x - 2;
	mod_y = y - 2;

	while (i < 4)
	{
		while (j < 4)
		{
			mlx_put_pixel(g->img, mod_x, mod_y, color);
			j++;
			mod_x++;
		}
		mod_x = x - 2;
		j = 0;
		mod_y++;
		i++;
	}
}

static void	draw_square (t_game *g, int x, int y, uint32_t color)
{
	int i;
	int j;
	int mod_x;
	int	mod_y;

	i = 0;
	j = 0;
	if (x == 0)
		x = 4;
	if (y == 0)
		y = 4; // to be changed when the coodinates are scaled
	mod_x = x - 4;
	mod_y = y - 4;

	while (i < 7)
	{
		while (j < 7)
		{
			mlx_put_pixel(g->img, mod_x, mod_y, color);
			j++;
			mod_x++;
		}
		mod_x = x - 4;
		j = 0;
		mod_y++;
		i++;
	}
}


static void draw_map(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (g->map_copy[y])
	{
		x = 0;
		while (g->map_copy[y][x])
		{
			if (g->map_copy[y][x] == '1')
				draw_square (g, x * 8, y * 8, get_color(0, 0, 0, 155));
			else
				draw_square (g, x * 8, y * 8, get_color(255, 255, 255, 155));
			if (is_news(g->map_copy[y][x]))
				draw_player (g, x * 8, y * 8, get_color(255, 0, 0, 155));
			x++;
		}
	y++;
	}
}

void	keybinding(mlx_key_data_t input, void *tmp)
{
	t_game	*g;

	g = tmp;
	if (input.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(g->mlx);
		return ;
	}
	if (input.key == MLX_KEY_RIGHT)
		printf("right\n");
	if (input.key == MLX_KEY_LEFT)
		printf("left\n");
	if (input.key == MLX_KEY_UP)
		printf("forward\n");
	if (input.key == MLX_KEY_DOWN)
		printf("backward\n");
}

// static	void dda(t_game *g)
// {
// 	int x;
// 	x = 0;
// 	while (x < WIDTH)
// 	{}
// }

void	rendering(t_game *g)
{
	draw_map(g);
	dda(g);
	mlx_image_to_window(g->mlx, g->img, 0, 0);
}

int	cub3d(t_game *g)
{
	g->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true);
	if (!g->mlx)
		return (-1);
	init_img_variables(g);
	print_variables(g);
	rendering(g);
	mlx_key_hook(g->mlx, &keybinding, g); //duplicating?
//	mlx_cursor_hook(); // optional (bonus)
	mlx_loop(g->mlx);
	mlx_terminate(g->mlx);
	return (0);
}
