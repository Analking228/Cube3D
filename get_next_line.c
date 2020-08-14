/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 20:09:29 by flexer            #+#    #+#             */
/*   Updated: 2020/06/22 18:56:48 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*add_buf(char *line, char *buf)
{
	char *tmp;

	if (line)
	{
		tmp = line;
		line = ft_strjoin(line, buf);
		free(tmp);
	}
	else
		line = ft_strdup(buf);
	return (line);
}

static char	*keeper_separator(char **line)
{
	size_t	i;
	char	*tmp;
	char	*keeper;
	size_t	len;

	if (!*line)
		return (NULL);
	len = ft_strlen(*line);
	i = 0;
	while ((*line)[i] != '\n' && i < len)
		i++;
	if (i < len)
	{
		tmp = *line;
		keeper = ft_substr(*line, i + 1, len);
		*line = ft_substr(*line, 0, i);
		if (!*line || !keeper)
			return (NULL);
		free(tmp);
		return (keeper);
	}
	else
		return (NULL);
}

int			get_next_line(int fd, char **line)
{
	static char	*keeper;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		size;

	if (fd < 0 || !line || read(fd, buf, 0) != 0 || (BUFFER_SIZE) < 1)
		return (-1);
	*line = keeper;
	while ((size = read(fd, buf, BUFFER_SIZE)))
	{
		buf[size] = 0;
		if (!(*line = add_buf(*line, buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (!(keeper = keeper_separator(line)) && size)
		return (-1);
	if (!*line)
		return (!(*line = ft_strdup(""))) ? -1 : 0;
	return (!keeper && !size) ? 0 : 1;
}
