/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:16:31 by samokhta          #+#    #+#             */
/*   Updated: 2024/10/03 13:16:33 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == s || len == 0)
		return (dest);
	if (d < s)
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i--)
			d[i] = s[i];
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len);

int main() {
    char src[] = "Hello, World!";
    char dest[50];

    printf("Before memmove:\n");
    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);

    ft_memmove(dest, src, strlen(src) + 1);

    printf("After memmove:\n");
    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);

    return 0;
}
*/
