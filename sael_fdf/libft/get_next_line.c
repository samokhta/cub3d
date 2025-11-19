/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:29:32 by samokhta          #+#    #+#             */
/*   Updated: 2025/02/20 16:57:58 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*set_line(char *line)
{
	size_t	i;
	char	*stash;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	stash = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
	}
	line[i + 1] = '\0';
	return (stash);
}

static char	*fill_line_buffer(int fd, char *stash, char *buffer)
{
	ssize_t	buffer_read;
	char	*temp;

	buffer_read = 1;
	while (buffer_read > 0)
	{
		buffer_read = read(fd, buffer, BUFFER_SIZE);
		if (buffer_read == -1)
		{
			free(stash);
			return (NULL);
		}
		if (buffer_read == 0)
			break ;
		buffer[buffer_read] = 0;
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE +1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		free(buffer);
		stash = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, stash, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	stash = set_line(line);
	return (line);
}

/*#include <stdio.h>
int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);


	return 0;
}*/
