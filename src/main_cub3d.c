/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:58:00 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/06 15:28:53 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
	(void)argc;
	(void)argv;

	if (argc != 2 || !check_filename(argv[1]))
		return (format_error(("wrong input format, try ./cub3d <map.cub>")), 0);
	if (!parsing(argv[1], &data.map))
		return (1);
	ft_window_init(&data);
	return (0);
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

