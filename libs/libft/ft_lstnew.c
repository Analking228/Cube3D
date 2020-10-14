/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:14:02 by flexer            #+#    #+#             */
/*   Updated: 2020/05/22 13:00:05 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*tmp;

	if ((tmp = (t_list *)malloc_mem(sizeof(t_list))))
	{
		tmp->content = content;
		tmp->next = NULL;
		return (tmp);
	}
	return (NULL);
}
