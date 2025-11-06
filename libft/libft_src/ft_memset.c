/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:44:49 by sravizza          #+#    #+#             */
/*   Updated: 2024/10/08 12:37:46 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(str + i) = (char) c;
		i++;
	}
	return (str);
}
/*
int main()
{
	char str[55] = "42 est la reponse a toutes les questions de l'univers";
	ft_memset(str + 10, 'X', 7*sizeof(char));
	printf("%s", str);
	return (0);
}*/