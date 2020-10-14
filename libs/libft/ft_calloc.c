/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 21:04:35 by flexer            #+#    #+#             */
/*   Updated: 2020/05/27 11:22:03 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t num, size_t sizeb)
{
	void	*memptr;

	if (num != 0 && sizeb != 0 && sizeb * num / num != sizeb)
		return (NULL);
	if (!(memptr = (void *)malloc(sizeb * num)))
		return (NULL);
	ft_bzero(memptr, num * sizeb);
	return (memptr);
}
