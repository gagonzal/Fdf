/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:13:08 by gagonzal          #+#    #+#             */
/*   Updated: 2018/09/12 18:17:02 by gagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int				get_line(char **line, t_list **src, char c)
{
	int		siz;
	int		i;
	char	*str;
	char	*tmp2;
	t_list	*tmp;

	siz = 0;
	tmp = *src;
	while (tmp && ((char*)tmp->content)[siz] && ((char*)tmp->content)[siz] != c)
		siz++;
	str = ft_strnew(siz);
	i = -1;
	while (str && ((char*)tmp->content)[++i] && ((char*)tmp->content)[i] != c)
		str[i] = ((char*)tmp->content)[i];
	*line = str;
	if (siz < (int)ft_strlen(tmp->content))
	{
		tmp2 = ft_strdup(tmp->content + (siz + 1));
		free(tmp->content);
		tmp->content = tmp2;
	}
	else
		ft_strclr(tmp->content);
	return (1);
}

static t_list	*get_data(t_list **old_line, int fd)
{
	t_list *tmp;

	tmp = *old_line;
	while (tmp)
	{
		if ((int)tmp->fd == fd)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", sizeof(char*));
	tmp->fd = fd;
	ft_lstadd(old_line, tmp);
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static	t_list	*old_line = NULL;
	int				ret;
	t_list			*curr;
	char			*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	curr = get_data(&old_line, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		tmp = ft_strjoin(curr->content, buf);
		free(curr->content);
		curr->content = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(curr->content))
		return (0);
	return (get_line(line, &curr, '\n'));
}
