/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:27:10 by samokhta          #+#    #+#             */
/*   Updated: 2024/10/02 13:27:11 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

long	ft_atoi(const char *str)
{
	long		i;
	long		sign;
	long		result;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (sign == -1 || str[i] == '+' )
		i++;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	return (result * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

// Declaration of your ft_atoi function
int ft_atoi(const char *str);

int main() {
    // Test cases
    //const char *test3 = "   + 6789";


    // Testing ft_atoi with different inputs

    printf("Input: '%s', Output: %d\n", " ", ft_atoi((void *)0));
	printf("Input: '%s', Output: %d\n", " ", atoi((void *)0));

    return 0;
}*/
