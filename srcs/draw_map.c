#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <math.h>

int	ft_abs(int c)
{
	return (c > 0 ? c : -c);
}

void	draw_line(t_mlx *mlx, t_coord a, t_coord b)
{
	t_line	line;

	a.x = (int)a.x;
	b.x = (int)b.x;
	a.y = (int)a.y;
	b.y = (int)b.y;
	line.start = a;
	line.end = b;
	line.dx = (int)ft_abs((int)b.x - (int)a.x);
	line.dy = (int)ft_abs((int)b.y - (int)a.y);
	line.sx = (int)a.x < (int)b.x ? 1 : -1;
	line.sy = (int)a.y < (int)b.y ? 1 : -1;
	line.e1 = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while((int)a.x !=(int) b.x || (int)a.y != (int)b.y)
	{
		if (bresen_alg(mlx, &line, &a, &b))
			break ;
	}
}

t_coord	threed_proj(t_coord p)
{
	t_coord new;
	double x;
	double y;
	double z;

	x = p.x;
	z = p.z;
	new.x = cos(0.5) * x + sin(0.5) * z;
	new.z = -sin(0.5) * x + cos(0.5) * z;
	y = p.y;
	z = new.z;
	new.y = cos(0.5) * y - sin(0.5) * z;
//	new.z = sin(0.5) * y + cos(0.5) * z;
	new.color = p.color;
	return (new);
}

t_coord	parra_project(t_map *map, int x, int y)
{
	t_coord curr;

	curr = *map->coord[y * map->width + x];
/*	
	curr.x -= (double)(map->width - 1) / 2.0f;
	curr.y -= (double)(map->height - 1) / 2.0f;
	curr.z -= (double)(map->depth_min + map->depth_max) / 3.0f;
//	curr = threed_proj(curr);
//	(void)map;
//	printf("x = %lf\n", curr.x);
//	printf("y = %lf\n", curr.y);
//	printf("z = %lf\n", curr.z);

	curr.x = (curr.x - curr.y) * (M_SQRT2 / 2);
	curr.y = (M_SQRT2 / sqrt(3)) * curr.z - ((curr.x + curr.y) / sqrt(6));
	*/
	int depth_max;
	depth_max = ft_abs(map->depth_min) + map->depth_max;
	curr.x = (curr.x - curr.y);
	curr.y -= curr.z;
	curr.x *= 32;
	curr.y *= 32;
	curr.x += WIN_W / 3;
	curr.y += WIN_H / 2;
//	printf("x = %lf\n", curr.x);
//	printf("y = %lf\n", curr.y);
//	printf("z = %lf\n", curr.z);
	return (curr);

}



void	draw_map(t_mlx *mlx)
{
	int x;
	int y;
	t_coord a;
	t_map *map;
	y = 0;
	map = mlx->map;
//	a = parra_project(map, 2, 2, mlx);
//	ft_putnbr(a.x);
//	ft_putchar('\n');
//	ft_putnbr(a.y);
//	ft_putchar('\n');
//	ft_putnbr(a.z);
	ft_bzero(mlx->img->ptr, WIN_W * WIN_H * mlx->img->bpp);
	while (y < map->height)
	{
		x = 0;
//		printf("colonne = %d\n", x);
		while(x < map->width)
		{
			a = parra_project(map, x, y);
//			printf("ligne = %d\n", y);
			if (y + 1 < map->height)
			{
				draw_line(mlx, a, parra_project(map, x, y + 1));
			}
			if (x + 1 < map->width)
			{
				draw_line(mlx, a, parra_project(map, x + 1, y));
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->img, 0, 0);

}
