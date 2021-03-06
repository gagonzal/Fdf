/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 12:15:53 by gagonzal          #+#    #+#             */
/*   Updated: 2018/11/06 10:54:48 by gagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_W 1920
# define WIN_H 1080

# include "../minilibx_mac/mlx.h"
# include "../libft/libft.h"

typedef struct	s_cam
{
	double	offsetx;
	double	offsety;
	double	x;
	double	y;
	double	depth_size;
	int		scale;
	double	**matrix;
}				t_cam;

typedef struct	s_coord
{
	double	x;
	double	y;
	double	z;
	int		color;
}				t_coord;

typedef struct	s_map
{
	int		width;
	int		height;
	int		depth_min;
	int		depth_max;
	t_coord	*coord;
}				t_map;

typedef struct	s_img
{
	void	*img;
	char	*ptr;
	int		bpp;
	int		s;
	int		e;
}				t_img;

typedef struct	s_mlx
{
	void	*mlx;
	void	*window;
	t_img	img;
	t_map	map;
	t_cam	cam;
	double	abs;
	double	ord;
	int		relief;
	int		projection;
}				t_mlx;

typedef struct	s_line
{
	t_coord	start;
	t_coord	end;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		e1;
	int		e2;
}				t_line;

int				init_map(int fd, t_map *map);
int				get_coord(int fd, t_map *map);
void			init_window(char *name, t_mlx *mlx);
void			draw_map(t_mlx *mlx);
void			math_test(t_coord c, t_map *map);
int				bresen_alg(t_mlx *mlx, t_line *line, t_coord *a, t_coord *b);
int				ft_abs(int c);
int				ft_check_file(char *map);
int				ft_check_spaces(char *line);

#endif
