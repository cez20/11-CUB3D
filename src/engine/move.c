#include "../include/cub3d.h"

void	look_right(t_ray *rc)
{
	rc->angle -= 0.1;
	if (rc->angle < 0)
		rc->angle += (2 * M_PI);
	rc->dir_x = cos(rc->angle) * 2;
	rc->dir_y = sin(rc->angle) * 2;
}

void	look_left(t_ray *rc)
{
	rc->angle += 0.1;
	if (rc->angle > (2 * M_PI))
		rc->angle -= (2 * M_PI);
	rc->dir_x = cos(rc->angle) * 2;
	rc->dir_y = sin(rc->angle) * 2;
}

void	forward(t_ray *rc)
{
	rc->pos_x += rc->dir_x;
	rc->pos_y += rc->dir_y;
}

void	backward(t_ray *rc)
{
	rc->pos_x -= rc->dir_x;
	rc->pos_y -= rc->dir_y;
}
