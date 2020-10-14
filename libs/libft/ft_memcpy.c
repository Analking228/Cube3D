/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:49:09 by flexer            #+#    #+#             */
/*   Updated: 2020/05/29 13:01:43 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrd;
	unsigned char	*ptrs;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	ptrd = (unsigned char *)dest;
	ptrs = (unsigned char *)src;
	while (n-- != 0)
	{
		ptrd[i] = ptrs[i];
		i++;
	}
	return (ptrd);
}
