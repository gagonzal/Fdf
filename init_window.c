#include "libft/libft.h"
#include "fdf.h"
#include "mlx.h"

t_img	*create_img(t_mlx *mlx)
{
	t_img *img;
	if (!(img = malloc(sizeof(t_img))))
		return (NULL);
	if ((img->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H)) == NULL)
		return (NULL);
	img->ptr = mlx_get_data_addr(img->img, &img->bpp, &img->size_line, &img->endian);
	img->bpp /= 8;
	return (img);
}

t_mlx	*init_window(char *name)
{
	t_mlx *mlx;

	if (!(mlx = malloc(sizeof(t_mlx))))
		return (NULL);
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIN_W, WIN_H, name);
	mlx->img = create_img(mlx);
	mlx->cam->x = 0.5;
	mlx->cam->y = 0.5;
	mlx->cam->scale = 32;
	mlx->cam->offsetx = WIN_W / 2;
	mlx->cam->offsety = WIN_H / 2;
	return (mlx);
}
