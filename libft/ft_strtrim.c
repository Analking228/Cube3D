/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 12:27:00 by flexer            #+#    #+#             */
/*   Updated: 2020/05/27 21:55:36 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

char		*ft_strtrim(char const *str, char const *set)
{
	char	*newstr;
	size_t	i;
	size_t	bgn;
	size_t	end;

	bgn = 0;
	if (!str || !set)
		return (NULL);
	end = ft_strlen(str);
	i = 0;
	while (str[bgn] && ft_inset(str[bgn], set))
		bgn++;
	while (end > bgn && ft_inset(str[end - 1], set))
		end--;
	newstr = (char*)ft_calloc((end - bgn + 1), sizeof(char));
	if (!newstr)
		return (NULL);
	while (bgn < end)
		newstr[i++] = str[bgn++];
	newstr[i] = 0;
	return (newstr);
}
