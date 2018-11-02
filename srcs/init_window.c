#include "../libft/libft.h"
#include "../includes/fdf.h"

t_cam	*init_cam_setup(t_map * map)
{
	t_cam *cam;
	if (!(cam = malloc(sizeof(t_cam))))
		return (NULL);
	if (map->width > 30)
	{
		cam->x = (WIN_W / 2) / map->width;
	}
	else
	{
		cam->x = (WIN_W / 2) / map->width;
	}
	if (map->height > 30)
	{
		cam->y = (WIN_H / 2) / map->height;
	}
	else
	{
		cam->y = (WIN_H / 2 ) /map->height;
	}
	cam->depth_size = (ft_abs(map->depth_min) + map->depth_max) / 5 ;
	return (cam);
}

t_img	*create_img(t_mlx *mlx)
{
	t_img *img;
	if (!(img = malloc(sizeof(t_img))))
		return (NULL);

	if ((img->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H)) == NULL)
	{
		ft_memdel((void**)(img));
		return (NULL);
	}
	img->ptr = mlx_get_data_addr(img->img, &img->bpp, &img->size_line, &img->endian);
	img->bpp /= 8;
	return (img);
}

t_mlx	*init_window(char *name, t_map *map)
{
	t_mlx *mlx;


	if (!(mlx = malloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->mlx = mlx_init()))
	{
		ft_memdel((void**)(&mlx));
		return (NULL);
	}
	if (!(mlx->window = mlx_new_window(mlx->mlx, WIN_W, WIN_H, name)))
	{
		mlx_destroy_window(mlx->mlx, mlx->window);
		return (NULL);
	}
	if(!(mlx->img = create_img(mlx)))
		return (NULL);
	if (!(mlx->cam = init_cam_setup(map)))
		return (NULL);
	mlx->abs = 0;
	mlx->ord = 0;
	mlx->relief = 0;
//	mlx->cam->x = 0.5;
//	mlx->cam->y = 0.5;
//	mlx->cam->scale = 32;
//	mlx->cam->offsetx = WIN_W / 2;
//	mlx->cam->offsety = WIN_H / 2;
	return (mlx);
}
