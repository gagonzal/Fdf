#include "fdf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <math.h>

void	math_test(t_coord c, t_map *map)
{
	printf("x = %lf\n", c.x);
	printf("width = %d\n", map->width);
	printf("y = %lf\n", c.y);
	printf("height = %d\n", map->height);
	printf("z = %lf\n", c.z);
	printf("depth_min = %d\n", map->depth_min);
	printf("depth_max = %d\n", map->depth_max);
	c.x -=(double)(map->width - 1) / 2.0f;
	c.y -=(double)(map->height - 1) / 2.0f;
	c.z -=(double)(map->depth_min + map->depth_max) / 2.0f;
	printf("new c.x = %lf\n", c.x);
	printf("new c.y = %lf\n", c.y);
	printf("new c.z = %lf\n", c.z);
	t_coord new;
	new.x = cos(0.5) * c.x + sin(0.5) * c.z;
	new.z = -sin(0.5) * c.x + cos(0.5) * c.z;
	double y;
	double z;
	y = c.y;
	z = new.z;
	new.y = cos(0.5) * y - sin(0.5) * (-sin(0.5) * c.x + cos(0.5) *c.z);
	new.z = sin(0.5) * y + cos(0.5) * z;
	printf("after proj p.x = %lf\n", new.x);
	printf("after proj p.y = %lf\n", new.y);
	printf("after proj p.z = %lf\n", new.z);
	new.x *= 32;
	new.y *= 32;
	new.x += WIN_W / 2;
	new.y += WIN_H / 2;
	printf("after map scale p.x = %lf\n", new.x);
	printf("after map scale p.y = %lf\n", new.y);
	printf("after map scale p.z = %lf\n", new.z);
	int dx = 658 - 630;
	int dy = 408 - 400;

}
