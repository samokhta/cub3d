/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael <sael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:32:47 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/13 17:10:14 by sael             ###   ########.fr       */
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

typedef struct s_data {
	void		*mlx;
	void		*win;
	t_img		wall_img;
	t_img		background_img;
	t_img		minimap_img;
	t_img		player_img;
	t_map		map;
	t_player	player;
}	t_data;
//note: ajouter plusieurs t_img pour la minimap/le fond
#endif