/*There are no mistakes, just happy accidents... And segfaults.*/

#include "../include/cub3d.h"

/*	while i don't hit anything, i keep walking around the grid
	adding the distance for later reference
	rc->side:  this will later indicate which texture to be used 
	Ex.: (Side 1 = NO, Side 2 = SO,  Side 3 = EA, Side 4 = WE)	*/
void	dda_time(t_ray *rc)
{
	while (rc->hit == 0)
	{
		if (rc->side_dis_x < rc->side_dis_y)
		{
			rc->side_dis_x += rc->delta_dis_x;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->side_dis_y += rc->delta_dis_y;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		if (rc->map[rc->map_y][rc->map_x] == '1')
			rc->hit = 1;
	}
}

void	raycaster(t_game *g)
{
	int	i;

	i = -1;
	floor_n_ceiling(g); //starts by projection ceiling and floor all over
	while (++i < WIDTH) // every 'i' is a slice in the screen
	{
		g->rc->hit = 0;
		set_ray_posdir(g, i); // calculates the ray position and direction on that 'i'
		set_step(g->rc);
		dda_time(g->rc); // calculates the distance to a wall (where collision happens) and identify which way the wall is facing
		set_line_len(g); // calculates the size of the line to be drawn
		bob_ross_line(g, i, g->rc->side); // draws each vertical slice
	}
}

//DEBUG PRINT
		/* if ((int)i % 320 == 0 || i ==480 || i == 959)
			printf("\t[%d]\tcameraX = %f / raydirX = %f / raydirY = %f / deltadistX = %f / deltadisY = %f / sidedisX = %f / sidedisY = %f\n", (int)i, g->rc->camera_x, g->rc->ray_dir_x, g->rc->ray_dir_y, g->rc->delta_dis_x, g->rc->delta_dis_y, g->rc->side_dis_x, g->rc->side_dis_y);*/