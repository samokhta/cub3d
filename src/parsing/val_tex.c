/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:27:32 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/19 15:59:55 by samokhta         ###   ########.fr       */
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
	if (*width != *height)
	{
		mlx_destroy_image(mlx, texture);
		return (format_error("Texture must be square"), NULL);
	}
	return (texture);
}

int	get_all_tex(t_data *data)
{
	int	width;
	int	height;

	if (!data->mlx)
		return (format_error("mlx not init"), 0);
	data->map.tex_no = get_tex(data->mlx, data->map.no, &width, &height);
	if (!data->map.tex_no)
		return (0);
	data->map.tex_size = width;
	data->map.tex_so = get_tex(data->mlx, data->map.so, &width, &height);
	if (!data->map.tex_so || width != data->map.tex_size)
		return (format_error("textures must be same size"), 0);
	data->map.tex_ea = get_tex(data->mlx, data->map.ea, &width, &height);
	if (!data->map.tex_ea || width != data->map.tex_size)
		return (format_error("textures must be same size"), 0);
	data->map.tex_we = get_tex(data->mlx, data->map.we, &width, &height);
	if (!data->map.tex_we || width != data->map.tex_size)
		return (format_error("textures must be same size"), 0);
	return (1);
}

void	free_textures(t_data *data)
{
	if (data->map.tex_no)
		free(data->map.tex_no);
	if (data->map.tex_so)
		free(data->map.tex_so);
	if (data->map.tex_ea)
		free(data->map.tex_we);
	if (data->map.tex_we)
		free(data->map.tex_ea);
	data->map.tex_no = NULL;
	data->map.tex_so = NULL;
	data->map.tex_ea = NULL;
	data->map.tex_we = NULL;
}
