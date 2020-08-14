/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 20:09:46 by flexer            #+#    #+#             */
/*   Updated: 2020/06/17 13:48:45 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	strl;
	size_t	newl;
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	i = 0;
	strl = ft_strlen(s);
	if (strl - 1 < (size_t)start)
		return (ft_strdup(""));
	if (start + len > strl)
		newl = strl - (size_t)start;
	else
		newl = len;
	if (!(sub = (char*)malloc(newl + 1)))
		return (NULL);
	while (i < newl)
	{
		sub[i] = ((char*)s)[(size_t)start + i];
		i++;
	}
	sub[newl] = 0;
	return (sub);
}

char	*ft_strjoin(char const *prestr, char const *sufstr)
{
	size_t		newl;
	size_t		i;
	size_t		j;
	char		*newptr;

	if (!prestr || !sufstr)
		return (NULL);
	i = 0;
	j = 0;
	newl = ft_strlen(prestr) + ft_strlen(sufstr) + 1;
	newptr = (char*)malloc(newl * sizeof(char));
	if (!newptr)
		return (NULL);
	while (prestr[i])
		newptr[j++] = prestr[i++];
	i = 0;
	while (sufstr[i])
		newptr[j++] = sufstr[i++];
	newptr[j] = 0;
	return (newptr);
}

char	*ft_strchr(const char *s, int c)
{
	char		*ptrs;

	ptrs = (char*)s;
	while ((*ptrs != '\0') && (*ptrs != c))
		ptrs += 1;
	if (*ptrs == c)
		return (ptrs);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*newstr;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	if (!(newstr = (char*)malloc(len + 1)))
		return (NULL);
	while (s[i] && i < len)
	{
		newstr[i] = s[i];
		i++;
	}
	newstr[i] = 0;
	return (newstr);
}

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
