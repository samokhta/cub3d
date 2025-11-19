/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:58:14 by samokhta          #+#    #+#             */
/*   Updated: 2024/10/10 16:58:16 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	nlen;

	i = 0;
	nlen = ft_strlen(to_find);
	if (nlen == 0)
		return ((char *)str);
	while (i + nlen <= len && str[i] != '\0')
	{
		if (ft_strncmp((str + i), to_find, nlen) == 0)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
