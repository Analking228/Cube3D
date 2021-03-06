/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:50:21 by flexer            #+#    #+#             */
/*   Updated: 2020/10/21 20:37:52 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_validate_line(char *line, t_all *all)
{
	while (ft_isblank(*line) && *line)
		line++;
	if (*line != '1' && *line != '\0')
		abort_cub("Error\nInvalid configuration instruction", all);
}

void		ft_validate_color(char *line, char clr, t_all *all)
{
	int		i;

	i = 1;
	if (clr == 'F' && all->map.f_color != -1)
		abort_cub("Error\nMultiple floor color instruction", all);
	if (clr == 'C' && all->map.c_color != -1)
		abort_cub("Error\nMultiple ceiling color instruction", all);
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ',')
			abort_cub("Error\nInvalid color configuration", all);
		i++;
	}
}

int			ft_validation(int argc, char **argv, t_all *all)
{
	int		is_scr;
	int		len;

	is_scr = FALSE;
	all->frame.mlx = NULL;
	if (argc >= 2)
	{
		len = ft_strlen(argv[1]) - 4;
		if (len <= 0 || ft_strncmp(argv[1] + len, ".cub\0", 5) != 0)
			abort_cub("Error\nInvalid first argument", all);
	}
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save\0", 7) == 0)
			is_scr = TRUE;
		else
			abort_cub("Error\nInvalid second argument", all);
	}
	if (argc > 3)
		abort_cub("Error\nInvalid number of arguments", all);
	return (argc == 1) ? abort_cub("Error\nInvalid first argument", all) : is_scr;
}

void		ft_validate_params(t_all *all)
{
	if (all->frame.w == -1 || all->frame.h == -1)
		abort_cub("Error\nNo resolution", all);
	if (all->texture.s.img == NULL)
		abort_cub("Error\nNo south texture", all);
	if (all->texture.n.img == NULL)
		abort_cub("Error\nNo north texture", all);
	if (all->texture.e.img == NULL)
		abort_cub("Error\nNo east texture", all);
	if (all->texture.w.img == NULL)
		abort_cub("Error\nNo west texture", all);
	if (all->texture.s.img == NULL)
		abort_cub("Error\nNo sprite texture", all);
	if (all->map.f_color == -1)
		abort_cub("Error\nNo floor color", all);
	if (all->map.c_color == -1)
		abort_cub("Error\nNo ceilling color", all);
}

void		ft_validate_map(t_all *all, char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != ' ' && map[i][j])
			{
				if (j == 0 || j == all->map.x - 1)
					abort_cub("Error\nInvalid map", all);
				if (i == 0 || i == all->map.y - 1)
					abort_cub("Error\nInvalid map", all);
				if (j + 1 < all->map.x && map[i][j + 1] == ' ')
					abort_cub("Error\nInvalid map", all);
				if (map[i][j - 1] == ' ' || map[i - 1][j] == ' ')
					abort_cub("Error\nInvalid map", all);
				if (i + 1 < all->map.y && map[i + 1][j] == ' ')
					abort_cub("Error\nInvalid map", all);
			}
		}
	}
}
