/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:32:09 by gagonzal          #+#    #+#             */
/*   Updated: 2018/11/06 11:13:49 by gagonzal         ###   ########.fr       */
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

	curr = map->coord[y * map->width + x];
	curr.x = (curr.x - curr.y) + mlx->abs;
	if (ft_abs(mlx->relief) != 10)
		curr.y -= curr.z / (10 + mlx->relief) - mlx->ord;
	else
		curr.y -= curr.z / (10 + (mlx->relief - 1)) - mlx->ord;
	curr.x *= mlx->cam.x;
	curr.y *= mlx->cam.y;
	curr.x += WIN_W / 2;
	curr.y += WIN_H / 2;
	return (curr);
}

void	draw_map(t_mlx *mlx)
{
	int		x;
	int		y;
	t_coord	a;

	y = 0;
	ft_bzero(mlx->img.ptr, WIN_W * WIN_H * mlx->img.bpp);
	while (y < mlx->map.height)
	{
		x = 0;
		while (x < mlx->map.width)
		{
			a = parra_project(&mlx->map, x, y, mlx);
			if (y + 1 < mlx->map.height)
				draw_line(mlx, a, parra_project(&mlx->map, x, y + 1, mlx));
			if (x + 1 < mlx->map.width)
				draw_line(mlx, a, parra_project(&mlx->map, x + 1, y, mlx));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img, 0, 0);
}
