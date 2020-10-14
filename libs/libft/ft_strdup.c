/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 21:56:29 by flexer            #+#    #+#             */
/*   Updated: 2020/06/04 14:30:21 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	char	*newstr;
	size_t	len;

	len = ft_strlen(str);
	newstr = (char *)calloc_mem(len + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, str, len);
	return (newstr);
}
