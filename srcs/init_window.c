/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 12:05:42 by gagonzal          #+#    #+#             */
/*   Updated: 2018/11/06 01:50:39 by gagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fdf.h"

void	init_cam_setup(t_mlx *mlx)
{
	mlx->cam.x = (WIN_W / 2) / mlx->map.width;
	mlx->cam.y = (WIN_H / 2) / mlx->map.height;
	mlx->cam.depth_size = (ft_abs(mlx->map.depth_min) + mlx->map.depth_max) / 5;
}

void	create_img(t_mlx *mlx)
{
	mlx->img.img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	mlx->img.ptr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, \
			&mlx->img.s, &mlx->img.e);
	mlx->img.bpp /= 8;
}

void	init_window(char *name, t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIN_W, WIN_H, name);
	create_img(mlx);
	init_cam_setup(mlx);
	mlx->abs = 0;
	mlx->ord = 0;
	mlx->relief = 0;
}
