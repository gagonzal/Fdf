/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:51:06 by gagonzal          #+#    #+#             */
/*   Updated: 2018/11/06 01:44:03 by gagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/get_next_line.h"
#include "../libft/libft.h"
#include "../includes/fdf.h"
#include <limits.h>

void	find_max_depth(t_map *map)
{
	int		x;
	int		y;
	int		min;
	int		max;
	t_coord	tmp;

	y = 0;
	min = INT_MAX;
	max = INT_MIN;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			tmp = map->coord[y * map->width + x];
			if (tmp.z < min)
				min = tmp.z;
			if (tmp.z > max)
				max = tmp.z;
			x++;
		}
		y++;
	}
	map->depth_min = min;
	map->depth_max = max;
}

t_coord	get_value(int x, int y, char *value)
{
	t_coord c;

	c.x = (double)x;
	c.y = (double)y;
	c.z = (double)ft_atoi(value);
	c.color = 0xFFFFFF;
	return (c);
}

int		get_coord(int fd, t_map *map)
{
	char	*line;
	char	**tab;
	int		x;
	int		y;
	int		ret;

	y = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		x = 0;
		tab = ft_strsplit(line, ' ');
		while (x < map->width)
		{
			map->coord[y * map->width + x] = get_value(x, y, tab[x]);
			free(tab[x]);
			x++;
		}
		free(line);
		free(tab);
		y++;
	}
	find_max_depth(map);
	return (1);
}
