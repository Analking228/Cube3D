/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 12:44:22 by flexer            #+#    #+#             */
/*   Updated: 2020/05/21 17:56:10 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = NULL;
	if (lst)
	{
		tmp = lst;
		while (tmp->next)
			tmp = tmp->next;
	}
	return (tmp);
}
