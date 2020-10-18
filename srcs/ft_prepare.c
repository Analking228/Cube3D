/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:11:26 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/20 20:12:08 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		initialization(t_all *all)
{
	all->frame.win = NULL;
	all->frame.mlx = NULL;
	all->text.e.img = NULL;
	all->text.w.img = NULL;
	all->text.s.img = NULL;
	all->text.n.img = NULL;
	all->text.spr.img = NULL;
	all->img.img = NULL;
	all->plr.x = 0;
	all->plr.y = 0;
	all->plr.sideways = FALSE;
	all->plr.angle = -1;
	all->plr.turn_dir = 0;
	all->plr.turn_speed = 5 * (M_PI / 180);
	all->plr.walk_dir = 0;
	all->plr.walk_speed = 5;
	all->plr.pos = 0;
	all->frame.w = -1;
	all->frame.h = -1;
	all->map.tab = NULL;
	all->map.f_clr = -1;
	all->map.c_clr = -1;
	all->map.sprites = 0;
}

static void		create_img(t_img *img, t_frame *screen, t_all *all)
{
	img->img = mlx_new_image(screen->mlx, screen->w, screen->h);
	if (img->img == NULL)
		exit_cub("Error\nmlx function failed", all);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, \
						&img->len, &img->endian);
	if (img->addr == NULL)
		exit_cub("Error\nmlx function failed", all);
}

void			ft_preparation(t_all *all, char *path, int bmp)
{
	initialization(all);
	if (!(all->frame.mlx = mlx_init()))
		exit_cub("Error\nmlx init failed", all);
	ft_parse(path, all);
	if (!(all->ray = malloc_mem(sizeof(t_ray) * all->frame.w)))
		exit_cub("Error\nmalloc for rays failed", all);
	create_img(&all->img, &all->frame, all);
	rendering(all);
	if (bmp == TRUE)
		ft_bmp(all);
	all->frame.win = mlx_new_window(all->frame.mlx, \
				all->frame.w, all->frame.h, "cub3D");
	if (all->frame.win == NULL)
		exit_cub("Error: mlx new win failed", all);
	mlx_put_image_to_window(all->frame.mlx, all->frame.win, all->img.img, 0, 0);
}
