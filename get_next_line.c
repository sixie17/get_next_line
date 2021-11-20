#include "get_next_line.h"
#include <stdio.h>

int	search_for_nl(char *s)
{
	size_t	i;

	i = 0;
	while(s[i] && s[i] != '\n')
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
	while(s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = (char *)ft_calloc(i + 1, sizeof(char));
	ft_strlcpy(line, s, i + 1);
	return(line);
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
	if(r <= 0 && !*buff[0])
		return(0);
	ret = get_line(*buff);
	tmp = ft_strdup(*buff + ft_strlen(ret));
	free(*buff);
	*buff = tmp;
	return(ret);
}

char	*get_next_line(int fd)
{
	ssize_t		r;
	char		*buff;
	char		*ret;
	static char	*line;

	if (BUFFER_SIZE <= 0 && read(fd, NULL, 0) < 0)
		return (0);
	if (!line)
	{
		buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buff)
			return (NULL);
		r = 1;
		while (!search_for_nl(buff) && r > 0)
		{
			ret = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
			if (!ret)
				return (0);
			r = read(fd, ret, BUFFER_SIZE);
			buff = ft_strjoin(buff, ret);
		}
		ret = get_line(buff);
		line = ft_strdup(buff + ft_strlen(ret));
		free(buff);
		buff = NULL;
		return (ret);
	}
	return(sub_gnl(fd, &line));
}