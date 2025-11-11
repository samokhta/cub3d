/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:11:28 by samokhta          #+#    #+#             */
/*   Updated: 2025/02/28 14:12:49 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	check_fdf(char **argv)
{
	char	**filename;
	int		i;

	filename = ft_split(argv[1], '.');
	i = 0;
	while (filename[i])
		i++;
	if (i == 0 || ft_strncmp(filename[i - 1], "fdf", 3) != 0)
	{
		free_split(filename);
		return (1);
	}
	free_split(filename);
	return (0);
}

int	count_line_size(char **size_count)
{
	int		size;

	size = 0;
	while (size_count[size])
		size++;
	return (size);
}
