/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:53:35 by gagonzal          #+#    #+#             */
/*   Updated: 2018/11/05 23:41:20 by gagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <limits.h>

int		ft_check_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if ((line[i] < '0' || line[i] > '9') && line[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

t_map	*get_map(int width, int height)
{
	t_map *map;

	if (!(map = malloc(sizeof(t_map))))
		return (NULL);
	map->width = width;
	map->height = height;
	map->depth_min = 0;
	map->depth_max = 0;
	if (!(map->coord = (t_coord**)malloc(sizeof(t_coord*) * (width * (height + 1)) + 1)))
		return (NULL);
	return (map);
}

int		find_width(char *line)
{
	char	**tmp;
	int		i;

	tmp = ft_strsplit(line, ' ');
	i = 0;
	while (tmp[i])
	{
		if (!(ft_check_line(tmp[i])))
		{
			i = -1;
			break ;
		}
		i++;
	}
	return (i);
}

int		ft_find_map_size(int fd, int *height)
{
	char	*line;
	int		ret;
	int		width;
	int		y;

	y = 0;
	width = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		if (y == 0)
		{
			if ((width = find_width(line)) == -1)
				return (0);
		}
		else if (find_width(line) != width)
			return (0);
		y++;
	}
	*height = y - 1;
	return (width);
}

int		init_map(int fd, t_map **map)
{
	int	width;
	int height;

	if (!(width = ft_find_map_size(fd, &height)))
	{
		return (1);
	}
	if ((*map = get_map(width, height)) == NULL)
	{
		return (2);
	}
	return (0);
}
