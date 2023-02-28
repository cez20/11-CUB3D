#include "../include/cub3d.h"

u_int32_t	get_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
