/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:50:21 by flexer            #+#    #+#             */
/*   Updated: 2020/10/21 20:37:52 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		ft_texture_import(char *path, t_img *texture, t_all *all)
{
	if (texture->img != NULL)
		abort_cub("Error\nMultiple texture including", all);
	texture->img = mlx_xpm_file_to_image(all->frame.mlx, \
			path, &texture->width, &texture->height);
	if (texture->img == NULL)
		abort_cub("Error\nInvalid texture file", all);
	texture->addr = mlx_get_data_addr(texture->img, \
				&texture->bpp, &texture->len, &texture->endian);
	if (texture->addr == NULL)
		abort_cub("Error\nInvalid texture file", all);
}

void		ft_texture(char *str, t_all *all, char type)
{
	while (*str && ft_isspace(*str))
		str++;
	str = str + 2;
	while (*str && ft_isspace(*str))
		str++;
	if (type == 'N')
		ft_texture_import(str, &all->texture.n, all);
	if (type == 'S')
		ft_texture_import(str, &all->texture.s, all);
	if (type == 'W')
		ft_texture_import(str, &all->texture.w, all);
	if (type == 'E')
		ft_texture_import(str, &all->texture.e, all);
	if (type == 's')
		ft_texture_import(str, &all->texture.spr, all);
}
