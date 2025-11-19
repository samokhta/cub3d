/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:54:52 by samokhta          #+#    #+#             */
/*   Updated: 2024/10/10 16:54:54 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digits(int n)
{
	size_t	count;

	count = 1;
	if (n < 0)
		n *= -1;
	while (n / 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	digits;
	char	*dest;
	long	num;

	num = n;
	digits = ft_count_digits(n);
	if (n < 0)
	{
		num *= -1;
		digits++;
	}
	dest = malloc(sizeof(char) * (digits + 1));
	if (!dest)
		return (NULL);
	dest[digits] = '\0';
	while (digits--)
	{
		dest[digits] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}
