/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:32:40 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/06 15:19:06 by samokhta         ###   ########.fr       */
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


//PARSING
int		parsing(char *file, t_map *map);
int 	assign_param(char *line, t_map *map);

//map
int		is_map(char *line);
char 	*copy_line(char *content, int max_len);
char	 **get_coor(t_list *lst, int max_length);
int		read_map(int fd, t_map *map);

//param
int 	assign_texture(char *line, char **param);
int		assign_color(char *line, int *param, int i_color);
int		assign_param(char *line, t_map *map);
int		read_params(int fd, t_map *map);

//utils_lst
t_list	*new_node(char *content);
void 	node_add_back(t_list **lst, t_list *new);
int 	ft_lstsize(t_list *lst);
void	free_lst(t_list **lst);

//utils_parsing
int		params_complete(t_map *map);
int		empty_line(char *str);
char	*clean_line(char *src);
int		get_player_coor(t_map *map);
void	skip_empty_lines(int fd);

//utils
void	format_error(char *msg);
void	free_params(t_map *map);
void	free_all(char **str);

//init
int		ft_isfilename(int c);
void	initialise_param(t_map *map);
int		check_filename(char *str);

//tests
void	print_params(t_map *map);
void	print_map(t_map *map);

//window_init
void	ft_pixel_put(t_img *img, int x, int y, unsigned int color);
int    key_hook(int keycode, t_data *data);
int    close_hook(t_data *data);
void    ft_window_init(t_data *dataptr);

#endif
