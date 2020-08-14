/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:27:36 by flexer            #+#    #+#             */
/*   Updated: 2020/05/20 13:36:55 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*tmp;

	tmp = lst;
	count = 0;
	if (tmp)
	{
		count++;
		while (tmp->next)
		{
			count++;
			tmp = tmp->next;
		}
	}
	return (count);
}
