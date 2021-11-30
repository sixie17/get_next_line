/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:19:38 by ysakine           #+#    #+#             */
/*   Updated: 2021/11/22 17:19:41 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	search_for_nl(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (s[i] == '\n');
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*get_line(char *s)
{
	char	*line;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = (char *)ft_calloc(i + 1, sizeof(char));
	ft_strlcpy(line, s, i + 1);
	return (line);
}

char	*sub_gnl(int fd, char **buff)
{
	ssize_t	r;
	char	*ret;
	char	*tmp;

	r = 1;
	while (!search_for_nl(*buff) && r > 0)
	{
		ret = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!ret)
			return (0);
		r = read(fd, ret, BUFFER_SIZE);
		*buff = ft_strjoin(*buff, ret);
	}
	if (r <= 0 && !*buff[0])
	{
		free(*buff);
		return (0);
	}
	ret = get_line(*buff);
	tmp = ft_strdup(*buff + ft_strlen(ret));
	free(*buff);
	*buff = tmp;
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*line[1024];

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (0);
	if (!line[fd])
	{
		line[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		read(fd, line[fd], BUFFER_SIZE);
		if (!*line[fd])
			return (0);
	}
	return (sub_gnl(fd, &line[fd]));
}
