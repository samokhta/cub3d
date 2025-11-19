/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:28:07 by samokhta          #+#    #+#             */
/*   Updated: 2025/03/07 16:16:46 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	init_img(t_mlx_img *img, t_mlx_data data)
{
	img->img = mlx_new_image(data.mlx, 1000, 1000);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

int	find_grid_size(t_size map_size)
{
	int	i;

	i = 0;
	if (map_size.x >= map_size.y)
	{
		while (map_size.x * (i + 1) < 700)
			i++;
	}
	else
	{
		while (map_size.y * (i + 1) < 700)
			i++;
	}
	return (i + 1);
}

void	init_data(t_mlx_data *data, char **argv)
{
	data->map_size.x = find_x(argv);
	data->map_size.y = find_y(argv);
	data->mlx = mlx_init();
	data->map = parse_file(argv, data->map_size);
	data->win = mlx_new_window(data->mlx, 1000, 1000, "zzzzzz");
	init_img(&data->img, *data);
}

void	draw(t_mlx_data data, int grid_size)
{
	t_size		map_size;
	t_size		increment;
	t_bresenham	x_bres;
	t_bresenham	y_bres;

	map_size = data.map_size;
	increment.x = 0;
	increment.y = 0;
	while (increment.y < map_size.y)
	{
		increment.x = 0;
		while (increment.x < map_size.x)
		{
			if (increment.x < map_size.x - 1)
				x_draw(increment, &x_bres, data, grid_size);
			if (increment.y < map_size.y - 1)
				y_draw(increment, &y_bres, data, grid_size);
			increment.x++;
		}
		increment.y++;
	}
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;
	int			grid_size;

	data.map_size.x = 0;
	data.map_size.y = 0;
	if (check_file(argc, argv) == 1)
		ft_error("Error");
	init_data(&data, argv);
	grid_size = find_grid_size(data.map_size);
	draw(data, grid_size);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	set_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
