/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:27:32 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/19 12:15:20 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*get_tex(void *mlx, char *path, int *width, int *height)
{
	void	*texture;

	if (!mlx || !path)
		return (NULL);
	texture = mlx_xpm_file_to_image(mlx, path, width, height);
	if (!texture)
		return (format_error("Cannot load texture"), NULL);
	return (texture);
}

int	validate_texture_sizes(t_data *data)
{
	int	std;
	int	cur_w;
	int	cur_h;

	mlx_get_image_size(data->map.no, &cur_w, &cur_h);
	if (cur_w != cur_h)
		return (format_error("textures are wrong size"), 0);
	std = cur_w;
	mlx_get_image_size(data->map.so, &cur_w, &cur_h);
	if (std != cur_w || cur_w != cur_h)
		return (format_error("textures are wrong size"), 0);
	mlx_get_image_size(data->map.ea, &cur_w, &cur_h);
	if (std != cur_w || cur_w != cur_h)
		return (format_error("textures are wrong size"), 0);
	mlx_get_image_size(data->map.we, &cur_w, &cur_h);
	if (std != cur_w || cur_w != cur_h)
		return (format_error("textures are wrong size"), 0);
	data->map.tex_size = std;
	return (1);
}

int	get_all_tex(t_data *data)
{
	int	width;
	int	height;

	if (!data->mlx)
		return (format_error("mlx not init"), 0);
	data->map.tex_no = get_tex(data->mlx, data->map.no,
			&width, &height);
	if (!data->map.tex_no)
		return (0);
	data->map.tex_so = get_tex(data->mlx, data->map.so,
			&width, &height);
	if (!data->map.tex_so)
		return (0);
	data->map.tex_ea = get_tex(data->mlx, data->map.ea,
			&width, &height);
	if (!data->map.tex_ea)
		return (0);
	data->map.tex_we = get_tex(data->mlx, data->map.we,
			&width, &height);
	if (!data->map.tex_we)
		return (0);
	// if (!validate_texture_sizes(data))
		// return (0);
	return (1);
}

void	free_textures(t_data *data)
{
	if (data->map.tex_no)
		mlx_destroy_image(data->mlx, data->map.tex_no);
	if (data->map.tex_so)
		mlx_destroy_image(data->mlx, data->map.tex_so);
	if (data->map.tex_ea)
		mlx_destroy_image(data->mlx, data->map.tex_ea);
	if (data->map.tex_we)
		mlx_destroy_image(data->mlx, data->map.tex_we);
	data->map.tex_no = NULL;
	data->map.tex_so = NULL;
	data->map.tex_ea = NULL;
	data->map.tex_we = NULL;
}
