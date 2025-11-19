/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:28:10 by samokhta          #+#    #+#             */
/*   Updated: 2025/03/07 16:22:40 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_
# include <math.h>
# include <string.h>
# include <errno.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

typedef struct s_point
{
	int				z;
	unsigned int	color;
}				t_point;

typedef struct s_size
{
	int	x;
	int	y;
}				t_size;

typedef struct s_mlx_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx_img;

typedef struct s_mlx_data {
	void		*mlx;
	void		*win;
	t_point		**map;
	t_size		map_size;
	t_mlx_img	img;
}				t_mlx_data;

typedef struct s_bresenham {
	float			x;
	float			y;
	float			x1;
	float			y1;
	int				z;
	int				z1;
	unsigned int	color;
}				t_bresenham;

void		my_mlx_pixel_put(t_mlx_img *img, int x, int y, unsigned int color);
void		bresenham(t_bresenham params, t_mlx_data data, int grid_size);
float		mod(float a);
float		max1(float a, float b);

int			close_free(t_mlx_data *data);
int			esc_hook(int keycode, t_mlx_data *data);
int			hex_to_decimal(char *hex);
void		set_hooks(t_mlx_data *data);
void		ft_error(char *string);
void		free_split(char **split);
void		free_map(t_point **map, t_size map_size);
void		print_map(t_point **map, t_size size);

t_point		set_defaults(void);
int			check_color(char *color);
int			occurence(char c);
int			parse_color(char *color);
t_point		parse_comma(char *point);
t_point		parse_point(char *point);
t_point		**real_parse(t_size size, int fd, char *line, char **split_line);
t_point		**parse_file(char **argv, t_size size);

int			check_fdf(char **argv);
int			count_line_size(char **size_count);
void		dimensions_error(char *line);
int			check_dimensions(int fd);
int			check_file(int argc, char **argv);
int			find_x(char **argv);
int			find_y(char **argv);

void		x_draw(t_size increment, t_bresenham *x_bres,
				t_mlx_data data, int grid_size);
void		y_draw(t_size increment, t_bresenham *y_bres,
				t_mlx_data data, int grid_size);
t_bresenham	x_set_params(int x, int y, t_point **map);
t_bresenham	y_set_params(int x, int y, t_point **map);

#endif