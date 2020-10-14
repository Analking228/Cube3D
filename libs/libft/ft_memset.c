/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 14:39:50 by flexer            #+#    #+#             */
/*   Updated: 2020/05/25 20:21:56 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*ptr;

	ptr = (unsigned char *)dest;
	ch = (unsigned char)c;
	while (n-- != 0)
		*(ptr++) = ch;
	return (dest);
}
