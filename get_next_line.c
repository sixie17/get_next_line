/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:25:37 by ysakine           #+#    #+#             */
/*   Updated: 2021/11/13 02:43:54 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_all(void *a, void *b)
{
	free (a);
	free (b);
}

size_t	doo(char **buff, int fd)
{
	size_t	r;

	ft_bzero(*buff, 2);
	r = read(fd, *buff, 1);
	return (r);
}

char	*get_next_line(int fd)
{
	char	*buff;
	char	*ret;
	char	*tmp;
	int		i;
	char	c;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	ret = (char *)malloc(sizeof(char));
	ft_bzero(ret, 1);
	c = 'a';
	i = fd;
	while (c != '\n' && c != '\0' && i >= 0)
	{
		buff = (char *) malloc(2 * sizeof(char));
		if (!buff)
			return (NULL);
		i = doo(&buff, fd);
		tmp = ret;
		ret = ft_strjoin(ret, buff);
		c = buff[0];
		free_all(tmp, buff);
	}	
	return (ret);
}
