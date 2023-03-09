#include "../include/cub3d.h"

void	look_left(t_ray *rc)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = rc->dir_x;
	old_plane_x = rc->plane_x;
	rc->dir_x = rc->dir_x * cos(-rc->rot_speed) \
				- rc->dir_y * sin(-rc->rot_speed);
	rc->dir_y = old_dir_x * sin (-rc->rot_speed) \
				+ rc->dir_y * cos (-rc->rot_speed);
	rc->plane_x = rc->plane_x * cos(-rc->rot_speed) \
				- rc->plane_y * sin(-rc->rot_speed);
	rc->plane_y = old_plane_x * sin (-rc->rot_speed) \
				+ rc->plane_y * cos (-rc->rot_speed);
}

void	look_right(t_ray *rc)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = rc->dir_x;
	old_plane_x = rc->plane_x;
	rc->dir_x = (rc->dir_x * cos(rc->rot_speed)) \
				- (rc->dir_y * sin(rc->rot_speed));
	rc->dir_y = (old_dir_x * sin (rc->rot_speed)) \
				+ (rc->dir_y * cos (rc->rot_speed));
	rc->plane_x = (rc->plane_x * cos(rc->rot_speed)) \
				- (rc->plane_y * sin(rc->rot_speed));
	rc->plane_y = (old_plane_x * sin (rc->rot_speed)) \
				+ (rc->plane_y * cos (rc->rot_speed));
}

void	strafe(t_ray *rc, char dir)
{
	if (dir == 'R')
	{
		if (rc->map[(int)(rc->pos_y)] \
				[(int)(rc->pos_x + rc->plane_x * rc->move_speed)] == '0')
			rc->pos_x += rc->plane_x * rc->move_speed;
		if (rc->map[(int)(rc->pos_y + rc->plane_y * rc->move_speed)] \
				[(int)(rc->pos_x)] == '0')
			rc->pos_y += rc->plane_y * rc->move_speed;
	}
	if (dir == 'L')
	{
		if (rc->map[(int)(rc->pos_y)] \
				[(int)(rc->pos_x - rc->plane_x * rc->move_speed)] == '0')
			rc->pos_x -= rc->plane_x * rc->move_speed;
		if (rc->map[(int)(rc->pos_y - rc->plane_y * rc->move_speed)] \
				[(int)(rc->pos_x)] == '0')
			rc->pos_y -= rc->plane_y * rc->move_speed;
	}
}

void	forward(t_ray *rc)
{
	if (rc->map[(int)rc->pos_y] \
			[(int)(rc->pos_x + rc->dir_x * rc->move_speed)] == '0')
		rc->pos_x += rc->dir_x * rc->move_speed;
	if (rc->map[(int)(rc->pos_y + rc->dir_y * rc->move_speed)] \
			[(int)rc->pos_x] == '0')
		rc->pos_y += rc->dir_y * rc->move_speed;
}

void	backward(t_ray *rc)
{
	if (rc->map[(int)rc->pos_y] \
			[(int)(rc->pos_x - rc->dir_x * rc->move_speed)] == '0')
		rc->pos_x -= rc->dir_x * rc->move_speed;
	if (rc->map[(int)(rc->pos_y - rc->dir_y * rc->move_speed)] \
			[(int)rc->pos_x] == '0')
		rc->pos_y -= rc->dir_y * rc->move_speed;
}
