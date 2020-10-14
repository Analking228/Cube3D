/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 16:56:12 by flexer            #+#    #+#             */
/*   Updated: 2020/05/27 21:29:32 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ptrd;
	unsigned char	*ptrs;
	unsigned char	ch;

	ch = (unsigned char)c;
	ptrs = (unsigned char *)src;
	ptrd = (unsigned char *)dest;
	while (n--)
	{
		*ptrd = *ptrs;
		if (*ptrs == ch)
			return (ptrd + 1);
		ptrd += 1;
		ptrs += 1;
	}
	return (NULL);
}
