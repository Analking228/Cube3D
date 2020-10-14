/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 17:31:26 by flexer            #+#    #+#             */
/*   Updated: 2020/05/25 10:45:46 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			strchecker(char *ptrb, char *ptrl, size_t len)
{
	char	*ptr1;
	char	*ptr2;
	size_t	n;

	n = len;
	ptr1 = ptrb;
	ptr2 = ptrl;
	while (n--)
	{
		if (*ptr1 != *ptr2)
			return (0);
		ptr1 += 1;
		ptr2 += 1;
	}
	return (1);
}

char		*ft_strnstr(const char *big, const char *little, size_t n)
{
	char	*ptrb;
	char	*ptrl;
	size_t	len;

	ptrb = (char *)big;
	ptrl = (char *)little;
	len = ft_strlen(ptrl);
	if (!*ptrl || !len)
		return (ptrb);
	while (n)
	{
		if (*ptrb == *ptrl)
			if ((strchecker(ptrb, ptrl, len)) && (n >= len))
				return (ptrb);
		ptrb += 1;
		n--;
	}
	return (NULL);
}
