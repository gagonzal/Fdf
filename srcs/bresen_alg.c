#include "../libft/libft.h"
#include "../includes/fdf.h"
#include <stdio.h>

void	put_pixel_to_img(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
	return ;
	*(int*)(img->ptr + ((x + y * WIN_W) * img->bpp)) = color;
}

double	ft_ilerp(double val, double start, double end)
{
	if (val == start)
		return (0.0);
	if (val == end)
		return (1.0);
	return((val - start) / (end - start));
}

int	bresen_alg(t_mlx *mlx, t_line *line, t_coord *a, t_coord *b)
{
	double percent;

	if (a->x < 0 || a->x >= WIN_W || a->y < 0 || a->y >= WIN_H
			|| b->x < 0 || b->x >= WIN_W || b->y < 0 || b->y >= WIN_H)
		return (1);

	if (line->dx > line->dy)

		percent = ft_ilerp((int)a->x, (int)line->start.x, (int)line->end.x);
	else
		percent = ft_ilerp((int)a->y, (int)line->start.y, (int)line->end.y);
//	printf("percent = %lf\n", percent);
	put_pixel_to_img(mlx->img, a->x, a->y, a->color);
	
	line->e2 = line->e1;
	if (line->e2 > -line->dx)
	{
		line->e1 -= line->dy;
		a->x += line->sx;
		/*if (line->sx == 1)
			ft_putendl("bouge vers la droite");
		else
			ft_putendl("bouge vers la gauche");*/
	}
	if (line->e2 < line->dy)
	{
		line->e1 += line->dx;
		a->y += line->sy;
		/*if (line->sy == 1)
			ft_putendl("bouge vers le bas");
		else
			ft_putendl("bouge vers le haut");*/
	}
	return (0);
}
