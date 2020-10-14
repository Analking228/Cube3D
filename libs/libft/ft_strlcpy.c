/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 14:12:42 by flexer            #+#    #+#             */
/*   Updated: 2020/06/04 14:32:16 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcpy(char *dest, const char *src, size_t size)
{
	char		*ptrs;

	ptrs = (char*)src;
	if (size > 0)
	{
		while (size && *ptrs != '\0')
		{
			*dest++ = *ptrs++;
			size--;
		}
		*dest = '\0';
	}
	return (ft_strlen(src));
}
