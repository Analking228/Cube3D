/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:44:12 by flexer            #+#    #+#             */
/*   Updated: 2020/05/05 17:15:15 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*ptrs;
	int		i;

	ptrs = (char *)s;
	i = ft_strlen(ptrs);
	ptrs += i;
	while (i-- >= 0)
	{
		if (*ptrs == c)
			return (ptrs);
		ptrs -= 1;
	}
	return (NULL);
}
