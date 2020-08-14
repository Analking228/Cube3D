/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 13:46:58 by flexer            #+#    #+#             */
/*   Updated: 2020/05/29 15:35:48 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_len(int n)
{
	int		len;

	len = 0;
	if (!n)
		return (1);
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_revstr(char *str)
{
	int		l;
	int		i;
	char	tmp;

	l = ft_strlen(str);
	i = 0;
	while (i < (l / 2))
	{
		tmp = str[i];
		str[i] = str[l - i - 1];
		str[l - i - 1] = tmp;
		i++;
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	int		numlen;
	int		minus;
	char	*str;
	int		i;

	i = 0;
	minus = 0;
	if (n < 0)
		minus = 1;
	numlen = minus + ft_len(n);
	str = (char *)ft_calloc(numlen + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[i] = 48;
	while (n)
	{
		str[i++] = 48 + ft_abs(n % 10);
		n /= 10;
	}
	if (minus)
		str[i] = 45;
	str[++i] = '\0';
	ft_revstr(str);
	return (str);
}
