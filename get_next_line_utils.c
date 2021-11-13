/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:21:07 by ysakine           #+#    #+#             */
/*   Updated: 2021/11/13 02:22:50 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dst[i])
		dst[i] = '\0';
	return (ft_strlen(src));
}

void	ft_bzero(char *s, size_t l)
{
	size_t	i;

	i = 0;
	while (i < l)
	{
		s[i] = '\0';
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*buff;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	size = len_s1 + len_s2 + 1;
	buff = malloc(size * sizeof(char) + 1);
	i = 0;
	if (!buff)
		return (0);
	ft_bzero(buff, size);
	while (i < len_s1)
	{
		buff[i] = s1[i];
		i++;
	}
	while (s2[i - len_s1])
	{
		buff[i] = s2[i - len_s1];
		i++;
	}
	return (buff);
}
