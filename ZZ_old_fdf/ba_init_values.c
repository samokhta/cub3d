/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ba_init_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:45:47 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/11 14:40:06 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_initial_values(t_data *data)
{
	data->img.mod.zoom = min(WINDOW_WIDTH / data->map.width,
			WINDOW_HEIGHT / data->map.height) * 0.5;
	if (data->img.mod.zoom < 1)
		data->img.mod.zoom = 1;
	data->img.mod.x_offset = (WINDOW_WIDTH
			- (data->map.width * data->img.mod.zoom));
	data->img.mod.y_offset = (WINDOW_HEIGHT
			- (data->map.height * data->img.mod.zoom));
	data->img.mod.altcoef = 5;
	data->img.mod.movecoef = data->map.height
		* data->map.width / (data->img.mod.zoom * 1000);
	if (data->img.mod.movecoef < 1)
		data->img.mod.movecoef = 1;
	data->img.mod.x_rot = 0;
	data->img.mod.y_rot = 0;
	data->img.mod.z_rot = 0;
	ft_initial_keys(data);
	return ;
}

void	ft_initial_keys(t_data *data)
{
	data->keys.x_off_p = 0;
	data->keys.x_off_m = 0;
	data->keys.y_off_p = 0;
	data->keys.y_off_m = 0;
	data->keys.zoom_p = 0;
	data->keys.zoom_m = 0;
	data->keys.alt_p = 0;
	data->keys.alt_m = 0;
	data->keys.reset = 0;
	data->keys.x_rot_p = 0;
	data->keys.x_rot_m = 0;
	data->keys.y_rot_p = 0;
	data->keys.y_rot_m = 0;
	data->keys.z_rot_p = 0;
	data->keys.z_rot_m = 0;
	data->keys.cav_view = 0;
	data->keys.neg_view = 0;
}

// void	ft_mlx_init(char **argv, t_data *data)
// {
// 	data->mlx_ptr = mlx_init();
// 	if (data->mlx_ptr == NULL)
// 		error("mlx_init fail");
// 	data->win_ptr = mlx_new_window(data->mlx_ptr,
// 			WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
// 	if (data->win_ptr == NULL)
// 		(free(data->mlx_ptr), error("mlx_new_window fail"));
// 	data->img.img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
// 	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
// 			&data->img.line_length, &data->img.endian);
// 	data->map = parsing(argv, (t_map){0, 0, NULL, NULL}, data);
// 	if (!data->map.height || !data->map.width || (
// 			!data->map.location) || !data->map.color)
// 		(ft_mlx_destroy(data, 1), error("file contains wrong format"));
// 	ft_initial_values(data);
// 	return ;
// }

// void	ft_mlx_hook(t_data *data)
// {
// 	mlx_loop_hook(data->mlx_ptr, &render, data);
// 	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
// 	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask,
// 		&handle_keyrelease, data);
// 	mlx_hook(data->win_ptr, 17, 0, &handle_closing, data);
// 	mlx_loop(data->mlx_ptr);
// 	return ;
// }

// void	ft_mlx_destroy(t_data *data, int map)
// {
// 	mlx_destroy_image(data->mlx_ptr, data->img.img);
// 	mlx_destroy_display(data->mlx_ptr);
// 	if (map)
// 		free_map(data);
// 	free(data->mlx_ptr);
// 	return ;
// }

