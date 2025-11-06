/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:49:25 by sravizza          #+#    #+#             */
/*   Updated: 2024/10/08 12:38:28 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(str + i) = 0;
		i++;
	}
}

/*int main()
{
	char str[55] = "42 est la reponse a toutes les questions de l'univers";
	ft_bzero(str, 7*sizeof(char));
	printf("%s", str);
	return (0);
}
*/