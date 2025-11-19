/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:45:48 by samokhta          #+#    #+#             */
/*   Updated: 2024/07/01 18:45:50 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	i = 0;
	if (dest == NULL)
		return (0);
	else
	{
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
}
/*
#include <stdio.h>
int main()
{
    char src[] = "hello, world";
    char *duplicate = ft_strdup(src);
    printf("%s\n", duplicate);
    return 0;
}
*/