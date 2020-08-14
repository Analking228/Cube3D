/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:47:54 by flexer            #+#    #+#             */
/*   Updated: 2020/05/29 13:01:54 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrd;
	unsigned char	*ptrs;

	if (!dest && !src)
		return (NULL);
	ptrd = (unsigned char *)dest;
	ptrs = (unsigned char *)src;
	if (ptrd < ptrs)
		while (n--)
			*ptrd++ = *ptrs++;
	else
	{
		ptrd += n - 1;
		ptrs += n - 1;
		while (n--)
			*ptrd-- = *ptrs--;
	}
	return (dest);
}
