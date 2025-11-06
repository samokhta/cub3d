/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:28:40 by sravizza          #+#    #+#             */
/*   Updated: 2025/10/30 11:27:52 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "cub3d.h"

//main
int		main(int argc, char **argv);
void	ft_mlx_init(char **argv, t_data *data);
void	ft_mlx_hook(t_data *data);
void	ft_mlx_destroy(t_data *data, int map);
int		check_filename(char *str);

//init_values
void	ft_initial_values(t_data *data);
void	ft_initial_keys(t_data *data);

//parsing
t_map	parsing(char **argv, t_map map, t_data *data);
int		width_count(char const *str, char c);
t_map	get_width_and_height(char **argv, t_map map, t_data *data);
t_map	get_location_and_color(char **argv, t_map map, t_data *data);
int		get_location_and_color2(t_map *map, int m, char **temp1);

//rendering
int		render(t_data *data);
void	img_pixel_put(t_img *data, int x, int y, int colour);
void	render_background(t_data *data);
void	render_fdf(t_data *data);

//bresenham
int		render_line(t_data *data, t_line line);
int		bresenham(t_data *data, t_line line, t_line_bres bres);
void	render_right_line(t_data *data, int x, int y);
void	render_down_line(t_data *data, int x, int y);

//get_coordinates
int		get_x(t_data *data, int x, int y);
int		get_y(t_data *data, int x, int y);

//rotation
void	rotate(t_data *data, int *x, int *y, int *z);
void	rotate_x(t_data *data, int *y, int *z);
void	rotate_y(t_data *data, int *x, int *z);
void	rotate_z(t_data *data, int *x, int *y);

//get_colors
int		get_color(int x, int y, t_line line);
int		get_red(int color);
int		get_green(int color);
int		get_blue(int color);
int		combine_rgb(int r, int g, int b);

//events_basics
int		handle_keypress(int keysym, t_data *ptr);
int		handle_keyrelease(int keysym, t_data *data);
int		handle_keyrelease2(int keysym, t_data *data);
void	update_hooks(t_data *data);
void	update_hooks2(t_data *data);

//events_actions
int		handle_closing(t_data *data);
int		handle_offset(int keysym, t_data *data);
int		handle_zoom(int keysym, t_data *data);
int		handle_reset(int keysym, t_data *data);
int		handle_rotation(int keysym, t_data *data);

//utils
void	error(char *msg);
void	free_all(char **str);
void	free_map(t_data *data);
int		ft_atoi_base16(const char *str);
int		min(int a, int b);

//utils_math
int		isox(int x, int y);
int		isoy(int x, int y, int z);
int		cavx(int x, int z);
int		cavy(int y, int z);
float	get_fract(int x, int y, t_line line);

#endif
