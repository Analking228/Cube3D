/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 20:09:29 by flexer            #+#    #+#             */
/*   Updated: 2020/06/22 18:56:48 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		mem_lstclear(t_list **lst)
{
	t_list *ptr;
	t_list *tmp;

	if (lst && *lst)
	{
		ptr = *lst;
		while (ptr)
		{
			tmp = ptr;
			ptr = ptr->next;
			free(tmp->content);
			free(tmp);
		}
		*lst = NULL;
	}
}

static t_list	*mem_lstnew(void *content)
{
	t_list *elem;

	if (!(elem = malloc(sizeof(t_list))))
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

static void		mem_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL)
	{
		del(lst->content);
		free(lst);
	}
}

static void		mem_lstremove(t_list **root, void *data)
{
	t_list	*node;
	t_list	*tmp;
	int		i;

	while (data == (*root)->content)
	{
		tmp = (*root)->next;
		mem_lstdelone(*root, free);
		(*root) = tmp;
	}
	node = *root;
	tmp = *root;
	i = 0;
	while (node != NULL)
	{
		if (data == node->content)
		{
			tmp->next = node->next;
			mem_lstdelone(node, free);
			node = tmp;
			i = 0;
		}
		tmp = i++ > 0 ? tmp->next : tmp;
		node = node != NULL ? node->next : node;
	}
}

void			mem_manager(void *ptr, int action)
{
	static t_list *collector = NULL;

	if (ptr == NULL)
		mem_lstclear(&collector);
	else if (action == ADD)
		ft_lstadd_front(&collector, mem_lstnew(ptr));
	else if (action == REMOVE)
		mem_lstremove(&collector, ptr);
}
