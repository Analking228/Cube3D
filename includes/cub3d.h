/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaptain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:52:47 by ccaptain          #+#    #+#             */
/*   Updated: 2020/09/23 12:51:52 by ccaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libs/opengl/mlx.h"
# include "../libs/libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <errno.h>
# include <stdint.h>

# define FALSE 0
# define TRUE 1
# define SPRITE 2
# define OUTSIDE 3

# define FOV 60 * (M_PI / 180)

# define ESC	53
# define LEFT	123
# define RIGHT	124
# define W		13
# define D		2
# define S		1
# define A		0

# pragma pack(1)

typedef struct		s_bmp_file_header
{
	uint16_t		type;
	uint32_t		size;
	uint16_t		reserved1;
	uint16_t		reserved2;
	uint32_t		off_bits;
}					t_bmp_file_header;

typedef struct		s_bmp_info_header
{
	uint32_t		size;
	int32_t			w;
	int32_t			h;
	uint16_t		planes;
	uint16_t		bit_cnt;
	uint32_t		compression;
	uint32_t		size_image;
	int32_t			x_pels_per_meter;
	int32_t			y_pels_per_meter;
	uint32_t		clr_used;
	uint32_t		clr_important;
}					t_bmp_info_header;

# pragma pack()

typedef struct		s_plr
{
	double			x;
	double			y;
	double			pos;
	int				turn_dir;
	int				walk_dir;
	int				sideways;
	double			angle;
	double			walk_speed;
	double			turn_speed;
}					t_plr;

typedef struct		s_ray
{
	double			angle;
	double			dist;
	double			hit_x;
	double			hit_y;
	int				is_up;
	int				is_down;
	int				is_left;
	int				is_right;
	int				is_vert;
}					t_ray;

typedef struct		s_ray_utils
{
	double			x;
	double			y;
	double			x_step;
	double			y_step;
	double			hit_x;
	double			hit_y;
	double			dist;
}					t_ray_utils;

typedef struct		s_render_utils
{
	double			dist;
	double			plane;
	double			height;
	double			top;
	double			step;
	double			text_pos;
	unsigned int	t_x;
	unsigned int	t_y;
	int				y;
	char			*color;
}					t_render_utils;

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				bpp;
	int				len;
	int				endian;
}					t_img;

typedef struct		s_map
{
	char			**tab;
	double			pix;
	int				f_color;
	int				c_color;
	int				sprites;
	int				x;
	int				y;
}					t_map;

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			angle;
	double			dist;
	double			size;
	double			x_ff;
	double			y_ff;
	double			step;
	double			tex_pos;
	unsigned int	*clr;
}					t_sprite;

typedef struct		s_texture
{
	t_img			n;
	t_img			s;
	t_img			w;
	t_img			e;
	t_img			spr;
}					t_texture;

typedef struct		s_frame
{
	void			*mlx;
	void			*win;
	int				pid;
	int				w;
	int				h;

}					t_frame;

typedef struct		s_all
{
	t_plr			plr;
	t_ray			*ray;
	t_img			img;
	t_map			map;
	t_texture		texture;
	t_sprite		*sprite;
	t_frame			frame;
}					t_all;

/*
						************* cub3d.c *************
*/

int					ft_wall(double x, double y, t_all *all);
void				plr_pos(t_all *all);

/*
						************* ft_bmp.c *************
*/

void				ft_bmp(t_all *all);

/*
						************* ft_color_utils.c *************
*/

int					create_trgb(int t, int r, int g, int b);
void				ft_backstage_floor(int x, int y, t_all *all, int color);
void				ft_backstage_ceilling(int x, int y, t_all *all, int color);

/*
						************* ft_map.c *************
*/

void				ft_parse_map(t_all *all, t_list *map_strs);

/*
						************* ft_parser.c *************
*/

void				ft_parse(char *map, t_all *all);

/*
						************* ft_prepare.c *************
*/

void				ft_preparation(t_all *all, char *path, int bmp);

/*
						************* ft_rays.c *************
*/

void				ft_raycast(t_all *all);

/*
						************* ft_render.c *************
*/

int					ft_rendering(t_all *all);
void				ft_mlx_pixel_put(t_img *img, int x, int y, int color);

/*
						************* ft_sprite.c *************
*/

void				ft_sprite(t_all *all);
void				ft_sprite_draw(t_all *all);

/*
						************* ft_terminators.c *************
*/

int					close_me(t_all *all);
int					abort_cub(char *error, t_all *all);

/*
						************* ft_texture.c *************
*/

void				ft_texture(char *str, t_all *all, char type);

/*
						************* ft_validate.c *************
*/

int					ft_validation(int argc, char **argv, t_all *all);
void				ft_validate_map(t_all *all, char **map);
void				ft_validate_params(t_all *all);
void				ft_validate_color(char *line, char clr, t_all *all);
void				ft_validate_line(char *line, t_all *all);

#endif
