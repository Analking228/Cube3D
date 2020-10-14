/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 11:12:01 by flexer            #+#    #+#             */
/*   Updated: 2020/05/27 22:02:42 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *prestr, char const *sufstr)
{
	size_t	newl;
	size_t	i;
	size_t	j;
	char	*newptr;

	if (!prestr || !sufstr)
		return (NULL);
	i = 0;
	j = 0;
	newl = ft_strlen(prestr) + ft_strlen(sufstr) + 1;
	newptr = (char *)calloc_mem(newl, sizeof(char));
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
