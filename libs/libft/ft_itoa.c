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

static int	num_count(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		count;
	long	num;

	num = n;
	count = num_count(n);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[count] = 0;
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	else if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[--count] = '0' + num % 10;
		num /= 10;
	}
	return (str);
}
