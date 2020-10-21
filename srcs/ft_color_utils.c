/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:50:21 by flexer            #+#    #+#             */
/*   Updated: 2020/10/21 20:37:52 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void		ft_backstage_floor(int x, int y, t_all *all, int color)
{
	int		i;
	int		j;
	int		width;
	int		height;

	i = x;
	width = all->frame.w;
	height = all->frame.h / 2;
	while (i < x + width)
	{
		j = y;
		while (j < y + height)
		{
			ft_mlx_pixel_put(&all->img, i, j, color);
			j++;
		}
		i++;
	}

}

void		ft_backstage_ceilling(int x, int y, t_all *all, int color)
{
	int		i;
	int		j;
	int		width;
	int		height;

	i = x;
	width = all->frame.w;
	height = all->frame.h / 2;
	while (i < x + width)
	{
		j = y;
		while (j < y + height)
		{
			ft_mlx_pixel_put(&all->img, i, j, color);
			j++;
		}
		i++;
	}
}