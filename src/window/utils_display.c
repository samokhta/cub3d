#include "cub3d.h"

void	ft_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	int		offset;
	char	*dst;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
	{
		printf("pixel out of bounds\n");
		return;
	}
	offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
	dst = img->addr + offset;
	*(unsigned int *)dst = color;
}

void	ft_img_init(void *mlx, t_img *new_img, int width, int height)
{
	new_img->img= mlx_new_image(mlx, width, height);
	new_img->height = height;
	new_img->width = width;
    new_img->addr = mlx_get_data_addr(new_img->img,
		&new_img->bits_per_pixel, &new_img->line_length, &new_img->endian);
	//printf("img init: img=%p addr=%p bpp=%d line=%d endian=%d\n",
	//	new_img->img, new_img->addr, new_img->bits_per_pixel,
	//	new_img->line_length, new_img->endian);
}
