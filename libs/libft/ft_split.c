/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 11:38:44 by flexer            #+#    #+#             */
/*   Updated: 2020/05/27 21:09:56 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] && s[i + 1])
				i++;
		}
		i++;
	}
	return (count);
}

static int	count_len(char const *str, char c)
{
	int		i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	return (i);
}

static void	*ft_free_mem(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
		free_mem(tab[i++]);
	free_mem(tab);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		word_count;
	char	*str;
	char	**tab;

	str = (char *)s;
	i = 0;
	j = 0;
	word_count = count_words(s, c);
	if (!s || !(tab = (char **)calloc_mem((word_count + 1), sizeof(char *))))
		return (NULL);
	while (j < word_count)
	{
		i = count_len(str, c);
		if (i > 0)
		{
			if (!(tab[j++] = ft_substr(str, 0, i)))
				return (ft_free_mem(tab));
		}
		i++;
		str += i;
	}
	tab[j] = NULL;
	return (tab);
}
