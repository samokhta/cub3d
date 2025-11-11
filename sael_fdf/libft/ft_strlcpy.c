/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:57:36 by samokhta          #+#    #+#             */
/*   Updated: 2024/10/10 16:57:38 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src [i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
/*

#include <stdio.h>
#include <string.h>


int main() {
    char src[] = "Hello, World!";
    char dst[20];
    size_t size = 9;

    // Testing ft_strlcpy
    size_t copied = ft_strlcpy(dst, src, size);

    printf("Source: '%s'\n", src);
    printf("Destination: '%s'\n", dst);
    printf("Number of characters copied: %zu\n", copied);

    return 0;
}*/
