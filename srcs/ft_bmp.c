/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:50:21 by flexer            #+#    #+#             */
/*   Updated: 2020/10/21 20:37:52 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_bmp_file_header		file_header(t_all *all)
{
	t_bmp_file_header	bf;

	bf.type = 0x4D42;
	bf.size = sizeof(t_bmp_file_header) + sizeof(t_bmp_info_header) + \
				all->frame.w * all->frame.h * 4;
	bf.reserved1 = 0;
	bf.reserved2 = 0;
	bf.off_bits = sizeof(t_bmp_file_header) + sizeof(t_bmp_info_header);
	return (bf);
}

static t_bmp_info_header		info_header(t_all *all)
{
	t_bmp_info_header	bi;

	bi.size = 40;
	bi.w = all->frame.w;
	bi.h = (all->frame.h - 1) * (-1);
	bi.planes = 1;
	bi.bit_cnt = all->img.bpp;
	bi.compression = 0;
	bi.size_image = 0;
	bi.x_pels_per_meter = 0;
	bi.y_pels_per_meter = 0;
	bi.clr_used = 0;
	bi.clr_important = 0;
	return (bi);
}

void					ft_bmp(t_all *all)
{
	int					fd;
	t_bmp_file_header	bf;
	t_bmp_info_header	bi;

	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	bf = file_header(all);
	bi = info_header(all);
	if (!write(fd, &bf, sizeof(bf)))
		abort_cub("Error\nFH error", all);
	if (!write(fd, &bi, sizeof(bi)))
		abort_cub("Error\nIH error", all);
	if (!write(fd, all->img.addr, all->frame.w * all->frame.h * 4))
		abort_cub("Error\nData error", all);
	close(fd);
	abort_cub("Screenshot has been saved", all);
}
