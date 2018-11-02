

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>

int	ft_error(int flag)
{
	if (flag == 1)
		ft_putendl("./fdf : wrong map values");
	if (flag == 2)
		ft_putendl("./fdf : couldn 't get_map");
	if (flag == 3)
		ft_putendl("./fdf : couldn 't init window");
	if (flag == 0)
		ft_putendl("./fdf : invalid	nb of arguments");
	if (flag == -1)
		ft_putendl("./fdf : couldnt open map");
	return (1);
}

void	ft_move_window(t_mlx *mlx, int key)
{
	if (key == 13)
		mlx->ord += 1;
	if (key == 1)
		mlx->ord -= 1;
	if (key == 2)
		mlx->abs += 1;
	if (key == 0)
		mlx->abs -= 1;
	if (key == 15)
		mlx->relief += 1;
	if (key == 17)
		mlx->relief -= 1;
	draw_map(mlx);
}

void	ft_zoom(t_mlx *mlx, int key)
{
	if (key == 12)
	{
		mlx->cam->x++;
		mlx->cam->y++;
	}
	if (key == 14)
	{
		mlx->cam->x--;
		mlx->cam->y--;
	}
	draw_map(mlx);
}

int	handle_key(int key, t_mlx *mlx)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 13 || key == 0 || key == 2 || key == 1 || key == 15 || key == 17)
		ft_move_window(mlx, key);
	if (key == 12 || key == 14)
	   ft_zoom(mlx, key);
	if (key == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->window);
		exit(EXIT_SUCCESS);
	}
	return (0);
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
	if (!(mlx = init_window("map", map)))
		return (ft_error(3));
	mlx->map = map;
//	ft_putnbr(map->coord[30]->x);
//	math_test(*map->coord[19 * 11 - 18], map);
	draw_map(mlx);
	mlx_key_hook(mlx->window, handle_key, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
