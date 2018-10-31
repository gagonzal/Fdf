

#include "fdf.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
/*
int	exit_key(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->window);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
*/
int	main(int ac, char **av)
{
	t_map *map;
	t_mlx	*mlx;
	int fd;

	if (!(fd = open(av[1], O_RDONLY)))
		return (1);
	init_map(fd, &map);
	close(fd);
	fd = open(av[1], O_RDONLY);
	get_coord(fd, &map);
//	mlx = init_window("map");
	mlx->map = map;
//	ft_putnbr(map->coord[30]->x);
	math_test(*map->coord[19 * 11 - 18], map);
//	draw_map(mlx);
//	mlx_key_hook(mlx->window, exit_key, mlx);
//	mlx_loop(mlx->mlx);
	return (0);
}
