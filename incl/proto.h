/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael <sael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:22:00 by samokhta          #+#    #+#             */
/*   Updated: 2025/11/21 21:16:47 by sael             ###   ########.fr       */
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

//utils
void	format_error(char *msg);
void	free_params(t_map *map);
void	free_double(char **str);
void	free_all(t_data *data);
int		ft_isfilename(int c);

//init
int		ft_isfilename(int c);
void	initialise_param(t_map *map);
int		check_filename(char *str);
void	initialise_player(t_player *player, t_map *map);

//PARSING
int		parsing(char *file, t_map *map);
int		assign_param(char *line, t_map *map);

//floodfill
int		validate_map(t_map *map);

//map
int		is_map(char *line);
char	*copy_line(char *content, int max_len);
char	**get_coor(t_map *map, t_list *lst, int max_length);
int		read_map(int fd, t_map *map, int max_length);

//param
int		assign_texture(char *line, char **param);
int		assign_color(char *line, int *param, int i_color);
int		assign_param(char *line, t_map *map);
int		read_params(int fd, t_map *map);

//utils_lst
t_list	*new_node(char *content);
void	node_add_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	free_lst(t_list **lst);

//utils_parsing
int		params_complete(t_map *map);
int		empty_line(char *str);
char	*clean_line(char *src);
int		get_player_coor(t_map *map);
char	*skip_empty_lines(int fd);

//utils_display
void	ft_pixel_put(t_img *img, int x, int y, unsigned int color);
void	ft_img_init(void *mlx, t_img *new_img, int width, int height);

//utils
void	format_error(char *msg);
void	free_params(t_map *map);
void	free_double(char **str);
void	free_all(t_data *data);
void	free_double(char **str);
void	free_all(t_data *data);

//init
int		ft_isfilename(int c);
void	initialise_param(t_map *map);
int		check_filename(char *str);
void	initialise_player(t_player *player, t_map *map);

//RAYCASTING
void	get_texture(t_data *data, t_ray *ray);
void	raycasting(t_data *data);
void	dda(t_data *data, t_ray *ray);
void	get_wall_dist(t_data *data, t_ray *ray);
void	get_wall_height(t_ray *ray);
void	draw_line(t_data *data, t_ray *ray, int x);
void	init_ray(t_data *data, t_ray *ray, int x);
void	init_step_and_side_dist(t_data *data, t_ray *ray);
void	free_textures(t_data *data);
int		get_all_tex(t_data *data);

//TEST
void	print_params(t_map *map);
void	print_map(char **map);
void	print_player_stats(t_player *player);

//window_init
int		key_hook(int keycode, t_data *data);
int		close_window(t_data *data);
void	ft_window_init(t_data *data);

//minimap_init
void	ft_minimap(t_data *data);
void	draw_square(t_data *data, int x, int y, int size);

//utils_minimap
int		max(int a, int b);
void	draw_square_bg(t_data *data, int x, int y, int size);
int		find_offset(int img_length, int map_length, int tile_size);

//background_init
void	ft_background_init(t_data *data);
int		rgb_to_int(int *color);

//movement
void	input_check(t_data *data);

#endif
