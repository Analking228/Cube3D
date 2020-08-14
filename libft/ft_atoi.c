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

int		polar_counter(int minus, const char *s, int i)
{
	int	number;

	number = 0;
	if (minus > 0)
	{
		while (ft_isdigit(s[i]))
		{
			number *= 10;
			number += s[i] - 48;
			i++;
		}
	}
	else
		while (ft_isdigit(s[i]))
		{
			number *= 10;
			number -= s[i] - 48;
			i++;
		}
	return (number);
}

int		ft_atoi(const char *s)
{
	int	minus;
	int	i;

	i = 0;
	minus = -1;
	while (ft_isspace(s[i]) && (s[i] != '\0'))
		i++;
	if (ft_isdigit(s[i]))
		return (polar_counter(-minus, s, i));
	else if (s[i] == 43)
		return (polar_counter(-minus, s, ++i));
	else if (s[i] == 45)
		return (polar_counter(minus, s, ++i));
	else
		return (0);
}
