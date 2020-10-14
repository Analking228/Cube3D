/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:50:21 by flexer            #+#    #+#             */
/*   Updated: 2020/05/26 22:37:52 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

int					ft_atoi(char const *str)
{
	int				n;
	unsigned long	r;

	n = 1;
	r = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			n = -1;
		str++;
	}
	while (*str != '\0' && ft_isdigit(*str))
	{
		if ((r * 10 + (*str - '0')) < r)
			return ((n > 0) ? -1 : 0);
		if ((r) > 8000)
			return ((int)(r * n));
		r = r * 10 + (*str - '0');
		str++;
	}
	return ((int)(r * n));
}
