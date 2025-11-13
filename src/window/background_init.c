#include "cub3d.h"

int	rgb_to_int(int *color)
{
	return ((color[0] << 16) | (color[1] << 8) | color[2]);
}

void	ft_background_init(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	ft_img_init(data->mlx, &data->background_img, WINDOW_WIDTH, WINDOW_HEIGHT);
	while (y < (WINDOW_HEIGHT / 2))
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			ft_pixel_put(&data->background_img, x, y, rgb_to_int(data->map.c));
			x++;
		}
		y++;
	}
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			ft_pixel_put(&data->background_img, x, y, rgb_to_int(data->map.f));
			x++;
		}
		y++;
	}
}
