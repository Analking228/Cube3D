/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:15:16 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/20 20:16:00 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_img			ft_render_side(t_all *all, t_ray ray, int *flag)
{
	*flag = 0;
	if (ray.is_vert)
	{
		if (ray.is_right)
			return (all->texture.w);
		else
		{
			*flag = 1;
			return (all->texture.e);
		}
	}
	else
	{
		if (ray.is_up)
			return (all->texture.n);
		else
		{
			*flag = 1;
			return (all->texture.s);
		}
	}
}

static t_render_utils	ft_render_colomn(t_all *all, int i, t_img texture)
{
	t_render_utils col;

	col.plane = (all->frame.w / 2.0) / tan(FOV / 2);
	all->ray[i].dist = all->ray[i].dist == 0 ? 1 : all->ray[i].dist;
	col.dist = all->ray[i].dist * cos(all->ray[i].angle - all->plr.angle);
	col.height = (all->map.pix / col.dist) * col.plane;
	col.top = all->frame.h / 2.0 - col.height / 2;
	if (all->ray[i].is_vert)
		col.t_x = remainder(all->ray[i].hit_y, all->map.pix) / \
					all->map.pix * texture.width;
	else
		col.t_x = remainder(all->ray[i].hit_x, all->map.pix) / \
					all->map.pix * texture.width;
	col.t_x = col.t_x & (unsigned int)(texture.height - 1);
	col.step = texture.height / col.height;
	col.text_pos = (col.top - all->frame.h / 2.0 + col.height / 2.0) * col.step;
	col.y = (int)col.top;
	return (col);
}

static void				ft_render_walls(t_all *all)
{
	t_img				side;
	t_render_utils		c;
	int					i;
	int					flag;

	i = 0;
	while (i < all->frame.w)
	{
		side = ft_render_side(all, all->ray[i], &flag);
		c = ft_render_colomn(all, i, side);
		while (c.y < c.top + c.height)
		{
			c.t_y = (unsigned int)c.text_pos & ((unsigned int)side.height - 1);
			c.color = !flag ? side.addr + (c.t_y * side.len + c.t_x *
						(side.bpp / 8)) : side.addr + (c.t_y * side.len +
							((64 - c.t_x) % 64) * (side.bpp / 8));
			c.text_pos += c.step;
			if (c.y >= 0 && c.y < all->frame.h && i >= 0 && i < all->frame.w)
				my_mlx_pixel_put(&all->img, i, c.y, *(unsigned int *)c.color);
			c.y++;
		}
		i++;
	}
}

int						ft_rendering(t_all *all)
{
	mlx_do_sync(all->frame.mlx);
	ft_backstage_ceilling(0, 0, all, all->map.c_color);
	ft_backstage_floor(0, all->frame.h / 2, all, all->map.f_color);
	plr_pos(all);
	ft_raycast(all);
	ft_render_walls(all);
	ft_sprite(all);
	return (1);
}
