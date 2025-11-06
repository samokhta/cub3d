/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:48:01 by sravizza          #+#    #+#             */
/*   Updated: 2024/10/15 18:00:21 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!src)
		return (0);
	if (start >= ft_strlen(src))
		return (ft_strdup(""));
	else if (len > ft_strlen(src + start))
		len = ft_strlen(src + start);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while ((src[i] && i < len))
	{
		dest[i] = src[start + i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/*
int main()
{
	char *str;

	str = ft_substr("XstrX", 1, 3);
	printf("str: %s\n", str);
	free(str);
	return(0);
}*/