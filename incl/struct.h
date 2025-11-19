/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:32:47 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/19 13:26:38 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub3d.h"

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
	int		p_row;
	int		p_col;
	char	p_dir;
	t_list	*lst;
	int		height;
	int		width;
	char	**coor;
	int		tex_size;
	void	*tex_no;
	void	*tex_so;
	void	*tex_ea;
	void	*tex_we;
}	t_map;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_player{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_key
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left_arr;
	bool	right_arr;
	bool	esc;
}	t_key;

typedef struct s_ray{
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	d_dist_x;
	double	d_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	void	*texture;
	int		tex_x;
	double	wall_x;
}	t_ray;

typedef struct s_data {
	void		*mlx;
	void		*win;
	t_img		screen_img;
	t_img		minimap_img;
	t_map		map;
	t_key		key;
	t_player	player;
}	t_data;

//note: ajouter plusieurs t_img pour la minimap/le fond
#endif