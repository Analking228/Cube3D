/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:03:54 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/20 20:07:58 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		ft_player(char wall, int x, int y, t_all *all)
{
	if (all->plr.angle != -1 || all->plr.x != 0 || all->plr.y != 0)
		abort_cub("Error\nMultiple player position", all);
	all->plr.x = x + 0.5;
	all->plr.y = y + 0.5;
	if (wall == 'N')
		all->plr.angle = 3 * M_PI / 2;
	else if (wall == 'S')
		all->plr.angle = M_PI / 2;
	else if (wall == 'W')
		all->plr.angle = M_PI;
	else if (wall == 'E')
		all->plr.angle = 0;
}

static void		ft_align(t_all *all, int max)
{
	int			i;
	char		*tmp;

	i = 0;
	while (all->map.tab[i] != NULL)
	{
		tmp = all->map.tab[i];
		all->map.tab[i] = malloc_mem(sizeof(char) * max + 1);
		ft_memset(all->map.tab[i], ' ', max);
		all->map.tab[i][max] = '\0';
		ft_memcpy(all->map.tab[i], tmp, ft_strlen(tmp));
		free_mem(tmp);
		i++;
	}
	all->map.x = max;
	all->map.y = i;
	if (all->plr.pos <= 0)
		abort_cub("Error\nNo player position", all);
}



static void		ft_parse_line(char *str, int y, t_all *all)
{
	int			x;

	x = 0;
	if (!(ft_strchr(str, '1')))
		abort_cub("Error\nString after map", all);
	while (str[x])
	{
		if (str[x] == 'N' || str[x] == 'S' || str[x] == 'W' || str[x] == 'E')
		{
			all->plr.pos = 1;
			ft_player(str[x], x, y, all);
		}
		else if (str[x] == '2')
			all->map.sprites++;
		else if (str[x] != '0' && str[x] != '1' && str[x] != ' ')
			abort_cub("Error\nInvalid map", all);
		x++;
	}
}

void			ft_parse_map(t_all *all, t_list *map_strs)
{
	size_t		y;
	size_t		m;

	y = 0;
	m = 0;
	while (map_strs && ft_atoi(map_strs->content) == 0)
		map_strs = map_strs->next;
	if (!(all->map.tab = malloc_mem(sizeof(char *) * (ft_lstsize(map_strs) + 1))))
		abort_cub("Error\nMalloc failed", all);
	while (map_strs)
	{
		ft_parse_line(map_strs->content, y, all);
		all->map.tab[y++] = map_strs->content;
		m = m < ft_strlen(map_strs->content) ? ft_strlen(map_strs->content) : m;
		map_strs = map_strs->next;
	}
	all->map.tab[y] = NULL;
	ft_align(all, m);
	ft_validate_map(all, all->map.tab);
	m = m < y ? y : m;
	all->map.pix = all->frame.h > all->frame.w \
				? all->frame.h / m : all->frame.w / m;
	all->plr.x *= all->map.pix;
	all->plr.y *= all->map.pix;
	ft_sprite_draw(all);
}
