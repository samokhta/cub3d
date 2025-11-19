/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:00:46 by samokhta          #+#    #+#             */
/*   Updated: 2024/10/10 17:00:48 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	target;

	target = (char)c;
	while (*s && *s != target)
		s++;
	if (*s == target)
		return ((char *)s);
	else
		return (0);
}
