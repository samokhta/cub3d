/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:27:21 by sravizza          #+#    #+#             */
/*   Updated: 2025/10/30 11:27:52 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub3d.h"

typedef struct s_mod
{
	int		zoom;
	int		x_offset;
	int		y_offset;
	int		altcoef;
	int		movecoef;
	double	x_rot;
	double	y_rot;
	double	z_rot;
}			t_mod;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_mod	mod;
}			t_img;

typedef struct s_map
{
	int		width;
	int		height;
	int		*location;
	int		*color;
}			t_map;

typedef struct s_keys
{
	int		x_off_p;
	int		x_off_m;
	int		y_off_p;
	int		y_off_m;
	int		zoom_p;
	int		zoom_m;
	int		alt_p;
	int		alt_m;
	int		reset;
	int		x_rot_p;
	int		x_rot_m;
	int		y_rot_p;
	int		y_rot_m;
	int		z_rot_p;
	int		z_rot_m;
	int		cav_view;
	int		neg_view;
}			t_keys;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	map;
	t_keys	keys;
}			t_data;

typedef struct s_line
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		c0;
	int		c1;
}			t_line;

typedef struct s_line_bres
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		d;
}			t_line_bres;

#endif
