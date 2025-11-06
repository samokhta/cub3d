/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:52:29 by sravizza          #+#    #+#             */
/*   Updated: 2024/10/14 22:35:11 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			break ;
		i++;
	}
	if (str[i] == (char) c)
		return ((char *) str + i);
	return (0);
}

/*nclude <stdlib.h>
int main ()
{
	printf("%s", )

}*/