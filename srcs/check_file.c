/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:20:30 by gagonzal          #+#    #+#             */
/*   Updated: 2018/11/05 11:25:04 by gagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_check_file(char *map)
{
	char *tmp;

	tmp = map + ft_strlen(map) - 4;
	if (ft_strcmp(tmp, ".fdf"))
	{
		ft_putstr("./fdf : wrong file type\n");
		return (1);
	}
	return (0);
}
