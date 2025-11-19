/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:58:43 by samokhta          #+#    #+#             */
/*   Updated: 2024/10/10 16:58:44 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check_set(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_start_count(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_check_set(s1[i], set) == 1)
		i++;
	return (i);
}

static size_t	ft_end_count(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = 0;
	if (i == 0)
		return (0);
	i--;
	while (i > 0 && ft_check_set(s1[i], set) == 1)
	{
		i--;
		j++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start_trim;
	size_t	end_trim;
	size_t	s1_len;
	char	*dest;

	i = 0;
	s1_len = ft_strlen(s1);
	start_trim = ft_start_count(s1, set);
	end_trim = ft_end_count(s1, set);
	if (start_trim >= s1_len || end_trim >= s1_len)
		return (ft_strdup(""));
	dest = malloc(sizeof(char) * (s1_len - start_trim - end_trim + 1));
	if (!dest)
		return (NULL);
	while ((start_trim + i) < (s1_len - end_trim))
	{
		dest[i] = s1[start_trim + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
