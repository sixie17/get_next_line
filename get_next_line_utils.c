/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:20:22 by ysakine           #+#    #+#             */
/*   Updated: 2021/11/22 17:20:24 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t l)
{
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	while (l--)
		s1[l] = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc (count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	i;

	str = (char *)ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	i = 0;
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buff;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	buff = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	i = 0;
	if (!buff)
		return (0);
	while (i < len_s1)
	{
		buff[i] = s1[i];
		i++;
	}
	while (i < len_s1 + len_s2)
	{
		buff[i] = s2[i - len_s1];
		i++;
	}
	free(s1);
	free(s2);
	return (buff);
}
