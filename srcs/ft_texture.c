/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:27:24 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/20 20:27:37 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		ft_texture_import(char *path, t_img *text, t_all *all)
{
	if (text->img != NULL)
		exit_cub("Error\nMultiple texture including", all);
	text->img = mlx_xpm_file_to_image(all->frame.mlx, \
			path, &text->width, &text->height);
	if (text->img == NULL)
		exit_cub("Error\nInvalid texture file", all);
	text->addr = mlx_get_data_addr(text->img, \
				&text->bpp, &text->len, &text->endian);
	if (text->addr == NULL)
		exit_cub("Error\nInvalid texture file", all);
}

void		ft_texture(char *str, t_all *all, char type)
{
	while (*str && ft_isspace(*str))
		str++;
	str = str + 2;
	while (*str && ft_isspace(*str))
		str++;
	if (type == 'N')
		ft_texture_import(str, &all->text.n, all);
	if (type == 'S')
		ft_texture_import(str, &all->text.s, all);
	if (type == 'W')
		ft_texture_import(str, &all->text.w, all);
	if (type == 'E')
		ft_texture_import(str, &all->text.e, all);
	if (type == 's')
		ft_texture_import(str, &all->text.spr, all);
}
