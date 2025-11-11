/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:48:13 by samokhta          #+#    #+#             */
/*   Updated: 2025/02/28 14:34:18 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point	set_defaults(void)
{
	t_point	default_values;

	default_values.color = 0xFFFFFF;
	default_values.z = 0;
	return (default_values);
}

int	check_color(char *color)
{
	int	i;

	i = 2;
	if (color[0] != '0' || color[1] != 'x' || ft_strlen(color) != 8)
		return (1);
	while (color[i])
	{
		if (!strchr("0123456789abcdefABCDEF", color[i]))
			return (1);
		i++;
	}
	return (0);
}

int	occurence(char c)
{
	int		i;
	char	*str;
	char	*str1;

	i = 0;
	str = "0123456789abcdef";
	str1 = "0123456789ABCDEF";
	while (str[i])
	{
		if (str[i] == c || str1[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	parse_color(char *color)
{
	int	i;
	int	res;

	i = 2;
	res = 0;
	while (color[i] && color[i] != '\n')
	{
		res = res * 16 + occurence(color[i]);
		i++;
	}
	return (res);
}
