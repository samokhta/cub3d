/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:58:00 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/17 12:29:13 by sravizza         ###   ########.fr       */
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
	//validate textures, needs mlx init;
	// ft_mlx_hook(&data);
	// ft_mlx_destroy(&data, 1);
	return (0);
}
