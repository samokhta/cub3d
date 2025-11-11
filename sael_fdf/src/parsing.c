/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:50:46 by samokhta          #+#    #+#             */
/*   Updated: 2025/02/28 14:33:11 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point	parse_comma(char *point)
{
	char	**split_point;
	t_point	res;
	int		i;

	split_point = ft_split(point, ',');
	if (!split_point)
		ft_error("line 39 exit");
	res = set_defaults();
	i = 0;
	while (split_point[i])
		i++;
	if (i != 2)
	{
		free_split(split_point);
		return (res);
	}
	res.z = ft_atoi(split_point[0]);
	if (check_color(split_point[1]) == 0)
		res.color = parse_color(split_point[1]);
	free_split(split_point);
	return (res);
}

t_point	parse_point(char *point)
{
	int		i;
	int		has_comma;
	t_point	res;

	i = 0;
	has_comma = 0;
	res = set_defaults();
	while (point[i])
	{
		if (!ft_strchr("-0123456789,abcdefABCDEFx", point[i]))
			return (res);
		i++;
	}
	if (ft_strchr(point, ','))
		has_comma = 1;
	if (has_comma == 0)
		res.z = ft_atoi(point);
	else
		res = parse_comma(point);
	return (res);
}

t_point	**map_alloc(t_size size)
{
	int		y;
	t_point	**res;

	y = 0;
	res = malloc(sizeof(t_point *) * (size.y));
	if (!res)
		ft_error("map_alloc failed");
	while (y < size.y)
	{
		res[y] = malloc(sizeof(t_point) * (size.x));
		if (res[y] == NULL)
			ft_error("map_alloc failed");
		y++;
	}
	return (res);
}

t_point	**real_parse(t_size size, int fd, char *line, char **split_line)
{
	int		x;
	int		y;
	t_point	**res;

	x = 0;
	y = 0;
	res = map_alloc(size);
	while (line)
	{
		x = 0;
		while (split_line[x])
		{
			res[y][x] = parse_point(split_line[x]);
			x++;
		}
		free(line);
		free_split(split_line);
		line = get_next_line(fd);
		split_line = ft_split(line, ' ');
		y++;
	}
	return (res);
}

t_point	**parse_file(char **argv, t_size size)
{
	int		fd;
	char	*line;
	char	**split_line;
	t_point	**res;

	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	split_line = ft_split(line, ' ');
	res = real_parse(size, fd, line, split_line);
	close(fd);
	return (res);
}
