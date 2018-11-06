/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:31:21 by gagonzal          #+#    #+#             */
/*   Updated: 2018/11/06 10:28:11 by gagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fdf.h"

void	put_pixel_to_img(t_img img, int x, int y, int color)
{
	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	*(int*)(img.ptr + ((x + y * WIN_W) * img.bpp)) = color;
}

int		bresen_alg(t_mlx *mlx, t_line *line, t_coord *a, t_coord *b)
{
	if (a->x < 0 || a->x >= WIN_W || a->y < 0 || a->y >= WIN_H
			|| b->x < 0 || b->x >= WIN_W || b->y < 0 || b->y >= WIN_H)
		return (1);
	put_pixel_to_img(mlx->img, a->x, a->y, a->color);
	line->e2 = line->e1;
	if (line->e2 > -line->dx)
	{
		line->e1 -= line->dy;
		a->x += line->sx;
	}
	if (line->e2 < line->dy)
	{
		line->e1 += line->dx;
		a->y += line->sy;
	}
	return (0);
}
