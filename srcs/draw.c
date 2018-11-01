/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 08:47:29 by cbarbier          #+#    #+#             */
/*   Updated: 2016/12/19 18:39:50 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	draw_line(t_fdf *env, t_point a, t_point b, char ground)
{
	int dx;
	int dy;
	int s[2];
	int err[2];

	dx = abs(b.x - a.x);
	dy = abs(b.y - a.y);
	s[0] = (a.x < b.x ? 1 : -1);
	s[1] = (a.y < b.y ? 1 : -1);
	err[0] = (dx > dy ? dx : -dy) / 2;
	while (a.x != b.x || a.y != b.y)
	{
		put_pixel(env, a, ground);
		err[1] = err[0];
		if (err[1] > -dx)
		{
			err[0] -= dy;
			a.x += s[0];
		}
		if (err[1] < dy)
		{
			err[0] += dx;
			a.y += s[1];
		}
	}
}

static void		computation(t_fdf *env, int xa, int ya)
{
	int		x;
	int		y;
	int		z;

	x = env->tab[ya][xa].x;
	y = env->tab[ya][xa].y;
	z = env->tab[ya][xa].z;
	env->tab[ya][xa].x = (x - y) * (M_SQRT2 / 2);
	env->tab[ya][xa].y = (M_SQRT2 / sqrt(3)) * z - ((x + y) / sqrt(6));
}

void			init_points(t_fdf *env, int dz)
{
	int		x;
	int		y;

	y = 0;
	while (y < env->height)
	{
		x = 0;
		while (x < env->width)
		{
			env->tab[y][x].x = env->d * x;
			env->tab[y][x].y = env->d * y;
			if (dz > 0)
				env->tab[y][x].z *= (abs(env->tab[y][x].z) > 200 ? 1 : 2);
			else
				env->tab[y][x].z = env->tab[y][x].z0;
			computation(env, x, y);
			set_max(env, x, y);
			x++;
		}
		y++;
	}
}

static	void	draw_lines(t_fdf *env, int x, int y)
{
	t_point p[2];

	p[0].z = env->tab[y][x].z;
	p[0].x = env->x0 + env->tab[y][x].x;
	p[0].y = env->y0 - env->tab[y][x].y;
	if (y < env->height - 1)
	{
		p[1].z = env->tab[y + 1][x].z;
		p[1].x = env->x0 + env->tab[y + 1][x].x;
		p[1].y = env->y0 - env->tab[y + 1][x].y;
		draw_line(env, p[0], p[1], (!p[0].z && !p[1].z ? 1 : 0));
	}
	if (x < env->width - 1)
	{
		p[1].z = env->tab[y][x + 1].z;
		p[1].x = env->x0 + env->tab[y][x + 1].x;
		p[1].y = env->y0 - env->tab[y][x + 1].y;
		draw_line(env, p[0], p[1], (!p[0].z && !p[1].z ? 1 : 0));
	}
}

void			draw_grid(t_fdf *env)
{
	int y;
	int x;

	y = 0;
	while (y < env->height)
	{
		x = 0;
		while (x < env->width)
		{
			draw_lines(env, x, y);
			x++;
		}
		y++;
	}
}
