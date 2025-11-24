/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:44:22 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/17 12:56:55 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	assign_texture(char *line, char **param)
{
	int		fd;
	int		i;
	char	*path;

	i = 3;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!line[i])
		return (format_error("no texture path"), 0);
	path = clean_line(line + 3);
	if (!path)
		return (format_error("texture malloc failed"), 0);
	if (ft_strncmp(path + ft_strlen(path) - 4, ".xpm", 4))
		return (free(path), format_error("texture is not .xpm"), 0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (free(path), format_error("cannot open texture path"), 0);
	close(fd);
	*param = path;
	return (1);
}

int	assign_color(char *line, int *param, int i_color)
{
	int	i;
	int	value;

	i = 2;
	while (line[i] && i_color < 3)
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (!ft_isdigit(line[i]))
			return (format_error("color: format wrong"), 0);
		value = ft_atoi(line + i);
		if ((value < 0) || (value > 255))
			return (format_error("color: out of bounds"), 0);
		param[i_color++] = value;
		while (ft_isdigit(line[i]))
			i++;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (i_color < 3 && line[i++] != ',')
			return (format_error("color: missing comma"), 0);
	}
	if (i_color != 3 || (line[i] && line[i] != '\n'))
		return (format_error("color: too many or too few"), 0);
	return (1);
}

int	assign_param(char *line, t_map *map)
{
	if (!ft_strncmp(line, "NO ", 3) && !(map->no))
		return (assign_texture(line, &map->no));
	if (!ft_strncmp(line, "SO ", 3) && !(map->so))
		return (assign_texture(line, &map->so));
	if (!ft_strncmp(line, "EA ", 3) && !(map->ea))
		return (assign_texture(line, &map->ea));
	if (!ft_strncmp(line, "WE ", 3) && !(map->we))
		return (assign_texture(line, &map->we));
	if (!ft_strncmp(line, "C ", 2) && (map->c[0] == -1))
		return (assign_color(line, map->c, 0));
	if (!ft_strncmp(line, "F ", 2) && (map->f[0] == -1))
		return (assign_color(line, map->f, 0));
	return (format_error("invalid parameters"), 0);
}

int	read_params(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	while (line && !params_complete(map))
	{
		if (!empty_line(line) && !assign_param(line, map))
			return (free(line), 0);
		free(line);
		if (params_complete(map))
			return (1);
		line = get_next_line(fd);
	}
	return (1);
}
