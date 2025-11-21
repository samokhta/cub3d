/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael <sael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:48:35 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/21 21:20:26 by sael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == '1' || line[i] == '0' || line[i] == ' '
				|| line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'E' || line[i] == 'W'))
			return (format_error("undesired char in map"), 0);
		i++;
	}
	return (1);
}

char	*copy_line(char *content, int max_len)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (max_len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (content[i])
	{
		dest[i] = content[i];
		i++;
	}
	while (i < max_len)
		dest[i++] = ' ';
	dest[i] = '\0';
	return (dest);
}

char	**get_coor(t_map *map, t_list *lst, int max_length)
{
	char	**dest;
	int		i;

	map->height = ft_lstsize(lst);
	map->width = max_length;
	dest = malloc(sizeof(char *) * (map->height + 1));
	if (!dest)
		return (format_error("malloc fail"), NULL);
	i = 0;
	while (lst)
	{
		dest[i] = copy_line(lst->content, max_length);
		if (!dest[i])
		{
			while (i-- > 0)
				free(dest[i]);
			free(dest);
			return (format_error("malloc fail"), NULL);
		}
		lst = lst->next;
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

char	*remove_nl(char *src)
{
	int	len;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	if (len > 0 && src[len - 1] == '\n')
		src[len - 1] = '\0';
	return (src);
}

int	read_map(int fd, t_map *map, int max_length)
{
	char	*line;
	t_list	*node;

	line = skip_empty_lines(fd);
	while (line)
	{
		if (empty_line(line))
			return (free(line), format_error("invalid char in map"), 0);
		remove_nl(line);
		if (!is_map(line))
			return (free(line), 0);
		node = new_node(line);
		if (!node)
			return (0);
		node_add_back(&map->lst, node);
		if ((int)ft_strlen(line) > max_length)
			max_length = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	map->coor = get_coor(map, map->lst, max_length);
	if (!(map->coor))
		return (0);
	return (1);
}

// int	read_map(int fd, t_map *map, int max_length, t_list *lst)
// {
// 	char	*line;
// 	int		line_length;
// 	t_list	*node;

// 	line = skip_empty_lines(fd);
// 	while (line && !empty_line(line))
// 	{
// 		remove_nl(line);
// 		if (!is_map(line))
// 			return (free(line), 0);
// 		node = new_node(line);
// 		if (!node)
// 			return (0);
// 		node_add_back(&lst, node);
// 		line_length = ft_strlen(line);
// 		if (line_length > max_length)
// 			max_length = line_length;
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	map->coor = get_coor(map, lst, max_length);
// 	if (!(map->coor))
// 		return (0);
// 	return (1);
// }
