/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael <sael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:58:00 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/18 13:59:44 by sael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_data *data)
{
	(void)data;
	ft_background_init(data);
	ft_minimap(data);
	input_check(data);
	mlx_put_image_to_window(data->mlx, data->win, data->screen_img.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->minimap_img.img, 20, 20);
	mlx_destroy_image(data->mlx, data->screen_img.img);	
	return (1);
}
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || !check_filename(argv[1]))
		return (format_error(("wrong input format, try ./cub3d <map.cub>")), 0);
	if (!parsing(argv[1], &data.map))
		return (1);
	initialise_player(&data.player, &data.map);
	print_player_stats(&data.player);
	ft_window_init(&data);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
