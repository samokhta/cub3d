/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:47:14 by samokhta          #+#    #+#             */
/*   Updated: 2025/03/03 13:45:38 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	dimensions_error(char *line)
{
	free(line);
	ft_error("dimension_error");
}

int	check_dimensions(int fd)
{
	char	*line;
	char	**size_count;
	int		size;
	int		size2;

	line = get_next_line(fd);
	size_count = ft_split(line, ' ');
	size = 0;
	size = count_line_size(size_count);
	free_split(size_count);
	while (line)
	{
		size2 = 0;
		size_count = ft_split(line, ' ');
		free(line);
		size2 = count_line_size(size_count);
		free_split(size_count);
		line = get_next_line(fd);
		if (size != size2)
			dimensions_error(line);
	}
	free(line);
	return (0);
}

int	check_file(int argc, char **argv)
{
	int		fd;

	fd = -1;
	if (argc != 2)
		return (1);
	if (check_fdf(argv) == 1)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	if (check_dimensions(fd) == 1)
		return (1);
	close(fd);
	return (0);
}

int	find_x(char **argv)
{
	int		x;
	int		y;
	int		fd;
	char	*line;
	char	**size_count;

	x = 0;
	y = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	size_count = ft_split(line, ' ');
	while (size_count[x])
		x++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		y++;
	}
	free(line);
	free_split(size_count);
	close(fd);
	if (x < 2 || y < 2)
		ft_error("map too small");
	return (x);
}

int	find_y(char **argv)
{
	int		x;
	int		y;
	int		fd;
	char	*line;
	char	**size_count;

	x = 0;
	y = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	size_count = ft_split(line, ' ');
	while (size_count[x])
		x++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		y++;
	}
	free(line);
	free_split(size_count);
	close(fd);
	if (x < 2 || y < 2)
		ft_error("map too small");
	return (y);
}
