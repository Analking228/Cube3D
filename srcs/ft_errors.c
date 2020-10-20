/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:00:03 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/23 15:47:50 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			close_me(t_all *all)
{
	abort_cub("Exit from cub.", all);
	return (-1);
}

static void	close_mlx(t_all *all)
{
	if (all->frame.mlx == NULL)
		return ;
	if (all->frame.win)
		mlx_destroy_window(all->frame.mlx, all->frame.win);
	if (all->texture.e.img)
		mlx_destroy_image(all->frame.mlx, all->texture.e.img);
	if (all->texture.n.img)
		mlx_destroy_image(all->frame.mlx, all->texture.n.img);
	if (all->texture.s.img)
		mlx_destroy_image(all->frame.mlx, all->texture.s.img);
	if (all->texture.w.img)
		mlx_destroy_image(all->frame.mlx, all->texture.w.img);
	if (all->texture.spr.img)
		mlx_destroy_image(all->frame.mlx, all->texture.spr.img);
	if (all->img.img)
		mlx_destroy_image(all->frame.mlx, all->img.img);
	if (all->frame.mlx)
		free(all->frame.mlx);
}

int			abort_cub(char *error, t_all *all)
{
	ft_putendl(error);
	close_mlx(all);
	free_mem(NULL);
	errno = errno == 11 ? 0 : errno;
	exit(errno);
	return (0);
}
