

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>

int	ft_error(int flag)
{
	if (flag == 1)
		ft_putend("./fdf : wrong map values");
	if (flag == 2)
		ft_putendl("./fdf : couldn 't get_map");
	if (flag == 3)
		ft_putendl("./fdf : couldn 't init window");
	if (flag == 0)
		ft_putendl("./fdf : too many arguments");
	if (!flags)
		ft_putendl("./fdf : couldnt open map");
	return (1);
}

int	exit_key(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->window);
		exit(EXIT_SUCCESS);
	}
	return (0);
	if (key 
}

int	main(int ac, char **av)
{
	t_map *map;
	t_mlx	*mlx;
	int ret;
	int fd;

	if (ac > 2 || ac == 1)
		return(ft_error(0));
	if (!(fd = open(av[1], O_RDONLY)))
		return (ft_error(-1));
	if ((ret = init_map(fd, &map)) > 0)
		return (ft_error(ret));
	close(fd);
	fd = open(av[1], O_RDONLY);
	get_coord(fd, &map);
	if (!(mlx = init_window("map"), map))
		return (ft_error(3));
	mlx->map = map;
//	ft_putnbr(map->coord[30]->x);
//	math_test(*map->coord[19 * 11 - 18], map);
	draw_map(mlx);
	mlx_key_hook(mlx->window, exit_key, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
