/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael <sael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:58:00 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/13 15:44:13 by sael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	mlx_loop(data.mlx);
	return (0);
}
