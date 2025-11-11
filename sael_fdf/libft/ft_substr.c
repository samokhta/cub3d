/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:59:00 by samokhta          #+#    #+#             */
/*   Updated: 2024/10/10 16:59:02 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	src_len;
	size_t	dest_len;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (start >= src_len)
		return (ft_strdup(""));
	dest_len = src_len - start;
	if (dest_len > len)
		dest_len = len;
	dest = (char *)malloc(sizeof(char) * (dest_len + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s + start, dest_len + 1);
	return (dest);
}
