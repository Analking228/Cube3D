/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 20:09:29 by flexer            #+#    #+#             */
/*   Updated: 2020/06/22 18:56:48 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		free_mem(void *ptr)
{
	mem_manager(ptr, REMOVE);
}

void		*malloc_mem(size_t sizeb)
{
	void	*ptr;

	ptr = malloc(sizeb);
	mem_manager(ptr, ADD);
	return (ptr);
}

void		*calloc_mem(size_t num, size_t sizeb)
{
	void	*ptr;

	ptr = ft_calloc(num, sizeb);
	mem_manager(ptr, ADD);
	return (ptr);
}
