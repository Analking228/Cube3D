/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:44:46 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/20 20:58:33 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int		ft_parse_count(char *str)
{
	int			cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == ',')
		{
			cnt++;
			str++;
		}
		else
			str++;
	}
	return (cnt);
}

static void		ft_parse_color(char *str, t_all *all, char color)
{
	char		**clr;
	int			rgb[3];
	int			i;

	while (*str && ft_isspace(*str))
		str++;
	str++;
	(ft_parse_count(str) == 2) ? validate_clr(str, color, all) :
				abort_cub("Error\nInvalid color configuration", all);
	if (!(clr = ft_split(str, ',')))
		abort_cub("Error\nMalloc failed", all);
	i = 0;
	while (clr && clr[i] != NULL)
	{
		if ((rgb[i] = ft_atoi(clr[i])) > 255 || clr[i] < 0 || i > 2)
			abort_cub("Error\nInvalid color configutation", all);
		free_mem(clr[i]);
		i++;
	}
	free_mem(clr);
	if (color == 'F')
		all->map.f_color = create_trgb(0, rgb[0], rgb[1], rgb[2]);
	else if (color == 'C')
		all->map.c_color = create_trgb(0, rgb[0], rgb[1], rgb[2]);
}

static void		ft_parse_resolution(char *str, t_all *all)
{
	int		width;
	int		height;

	mlx_get_screen_size(all->frame.mlx, &width, &height);
	if (all->frame.w != -1 || all->frame.h != -1)
		abort_cub("Error\nMultiple resolution", all);
	str = ft_strchr(str, 'R');
	str++;
	all->frame.w = ft_atoi(str);
	while (*str && ft_isspace(*str))
		str++;
	while (*str && ft_isdigit(*str))
		str++;
	all->frame.h = ft_atoi(str);
	while (*str && ft_isspace(*str))
		str++;
	while (*str)
	{
		if (ft_isspace(*str++) || ft_isalpha(*str++))
			abort_cub("Error\nInvalid resolution string", all);
	}
	if (all->frame.w <= 0 || all->frame.h <= 0)
		abort_cub("Error\nInvalid resolution", all);
	all->frame.w = all->frame.w > width ? width : all->frame.w;
	all->frame.h = all->frame.h > height ? height : all->frame.h;
}

static void		ft_parse_params(t_list *list, t_all *all)
{
	size_t		len;

	while (list)
	{
		len = ft_strlen(list->content);
		if (ft_strnstr(list->content, "R ", len))
			ft_parse_resolution(list->content, all);
		else if (ft_strnstr(list->content, "NO ", len))
			ft_texture(list->content, all, 'N');
		else if (ft_strnstr(list->content, "SO ", len))
			ft_texture(list->content, all, 'S');
		else if (ft_strnstr(list->content, "WE ", len))
			ft_texture(list->content, all, 'W');
		else if (ft_strnstr(list->content, "EA ", len))
			ft_texture(list->content, all, 'E');
		else if (ft_strnstr(list->content, "S ", len))
			ft_texture(list->content, all, 's');
		else if (ft_strnstr(list->content, "F ", len))
			ft_parse_color(list->content, all, 'F');
		else if (ft_strnstr(list->content, "C ", len))
			ft_parse_color(list->content, all, 'C');
		else
			validate_line(list->content, all);
		list = list->next;
	}
}

void			ft_parse(char *path, t_all *all)
{
	int			fd;
	char		*line;
	t_list		*map_strs;
	t_list		*tmp;
	int			gnl;

	if ((fd = open(path, O_RDONLY)) < 0)
		abort_cub("Error\nNo such file exists", all);
	map_strs = NULL;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		if (!(tmp = ft_lstnew(line)))
			abort_cub("Error\nMalloc failed", all);
		ft_lstadd_back(&map_strs, tmp);
	}
	if (gnl == -1)
		abort_cub("Error\nGNL failed", all);
	if (!(tmp = ft_lstnew(line)))
		abort_cub("Error\nMalloc failed", all);
	ft_lstadd_back(&map_strs, tmp);
	close(fd);
	ft_parse_params(map_strs, all);
	ft_validate_params(all);
	ft_parse_map(all, map_strs);
}
