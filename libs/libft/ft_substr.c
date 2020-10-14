/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 11:31:21 by flexer            #+#    #+#             */
/*   Updated: 2020/06/17 12:25:52 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (!(sub = (char*)calloc_mem(newl + 1, sizeof(char))))
		return (NULL);
	while (i < newl)
	{
		sub[i] = ((char*)s)[start + i];
		i++;
	}
	sub[newl] = 0;
	return (sub);
}
