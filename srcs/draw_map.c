/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:32:09 by gagonzal          #+#    #+#             */
/*   Updated: 2018/11/05 12:11:07 by gagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <math.h>

int		ft_abs(int c)
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
	while ((int)a.x != (int)b.x || (int)a.y != (int)b.y)
	{
		if (bresen_alg(mlx, &line, &a, &b))
			break ;
	}
}

t_coord	parra_project(t_map *map, int x, int y, t_mlx *mlx)
{
	t_coord curr;

	curr = *map->coord[y * map->width + x];
	curr.x = (curr.x - curr.y) + mlx->abs;
	curr.y -= curr.z / (8 + mlx->relief) - mlx->ord;
	curr.x *= mlx->cam->x;
	curr.y *= mlx->cam->y;
	curr.x += WIN_W / 3;
	curr.y += WIN_H / 3;
	return (curr);
}

void	draw_map(t_mlx *mlx)
{
	int		x;
	int		y;
	t_coord	a;
	t_map	*map;

	y = 0;
	map = mlx->map;
	ft_bzero(mlx->img->ptr, WIN_W * WIN_H * mlx->img->bpp);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			a = parra_project(map, x, y, mlx);
			if (y + 1 < map->height)
				draw_line(mlx, a, parra_project(map, x, y + 1, mlx));
			if (x + 1 < map->width)
				draw_line(mlx, a, parra_project(map, x + 1, y, mlx));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->img, 0, 0);
}
