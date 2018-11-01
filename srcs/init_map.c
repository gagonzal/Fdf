

#include "../includes/fdf.h"
#include <limits.h>

t_map	*get_map(int width, int height)
{
	t_map *map;
	if (!(map = malloc(sizeof(t_map))))
		return (NULL);
	map->width = width;
	map->height = height;
	map->depth_min = 0;
	map->depth_max = 0;
	if (!(map->coord = malloc(sizeof(t_coord *) * width * height)))
		return (NULL);
	return (map);
}


int	find_width(char *line)
{
	char **tmp;
	int i;

	tmp = ft_strsplit(line, ' ');
	i = 0;
	while (tmp[i])
	{
		i++;
	}
	return (i);
}

int	ft_find_map_size(int fd, int *height)
{
	char *line;
	int ret;
	int width;
	int y;

	
	y = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		if (y == 0)
			width = find_width(line);
		y++;
	}
	*height = y - 1;
	return (width);
}

int	init_map(int fd, t_map **map)
{
	int	width;
	int 	height;

	if (!(width = ft_find_map_size(fd, &height)))
		return (0);
	if ((*map = get_map(width, height)) == NULL)
		return (0);
//	ft_putnbr(width);
//	ft_putchar('\n');
//	ft_putnbr(height);
//	ft_putchar('\n');
	return (1);
}
