/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:21:51 by flexer            #+#    #+#             */
/*   Updated: 2020/05/05 17:23:51 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	*ptrs;

	ptrs = (char *)s;
	while ((*ptrs != '\0') && (*ptrs != c))
		ptrs += 1;
	if (*ptrs == c)
		return (ptrs);
	return (NULL);
}
