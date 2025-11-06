/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:59:36 by sravizza          #+#    #+#             */
/*   Updated: 2025/10/30 11:31:09 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return ;
}

void	error(char *msg)
{
	ft_printf("Error: %s\n", msg);
	perror("");
	exit(EXIT_FAILURE);
	return ;
}

void	free_map(t_data *data)
{
	free(data->map.location);
	free(data->map.color);
	return ;
}

int	ft_atoi_base16(const char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		i += 2;
	while (str[i])
	{
		result *= 16;
		if (str[i] >= '0' && str[i] <= '9')
			result += str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			result += str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			result += str[i] - 'a' + 10;
		i++;
	}
	return (result);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
