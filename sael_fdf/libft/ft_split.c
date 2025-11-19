/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:45:00 by samokhta          #+#    #+#             */
/*   Updated: 2025/02/26 16:58:02 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_all(char **result, int words_allocated)
{
	int	i;

	i = 0;
	while (i < words_allocated)
	{
		if (result[i])
			free(result[i]);
		i++;
	}
	free(result);
}

int	nb_sep(char const *str, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != sep && (i == 0 || str[i - 1] == sep))
			words++;
		i++;
	}
	return (words);
}

char	*ft_word_dup(char const *str, int *start, int finish)
{
	char	*word;
	int		j;
	int		s;

	s = *start;
	j = 0;
	word = (char *)malloc((finish - s + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (s < finish)
		word[j++] = str[s++];
	word[j] = '\0';
	*start = -1;
	return (word);
}

char	**allocate_result(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc((nb_sep(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i[3];

	i[0] = -1;
	i[1] = 0;
	i[2] = -1;
	result = allocate_result(s, c);
	if (!result)
		return (NULL);
	while (++i[0] <= ft_strlen(s))
	{
		if (s[i[0]] != c && i[2] < 0)
			i[2] = i[0];
		else if ((s[i[0]] == c || i[0] == ft_strlen(s)) && i[2] >= 0)
		{
			result[i[1]] = ft_word_dup(s, &i[2], i[0]);
			if (!result[i[1]++])
			{
				ft_free_all(result, i[1]);
				return (NULL);
			}
		}
	}
	result[i[1]] = 0;
	return (result);
}

/*#include "libft.h"

static void	free_strs(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static size_t	ft_count_words(const char *s, char sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == sep && s[i])
			i++;
		if (s[i] && s[i] != sep)
		{
			count++;
			while (s[i] && s[i] != sep)
				i++;
		}	
	}
	return (count);
}

static char	*ft_write_word(const char *s, size_t start, size_t finish)
{
	char	*word;
	size_t	i;

	word = malloc(sizeof(char) * (finish - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < finish)
	{
		word[i] = s[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_process_split(char **res, const char *s, size_t len, char c)
{
	size_t	i;
	size_t	j;
	int		s_word;

	i = 0;
	j = 0;
	s_word = -1;
	while (i <= len)
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == len) && s_word >= 0)
		{
			res[j] = ft_write_word(s, s_word, i);
			if (!res[j])
			{
				free_strs(res, j);
				return (1);
			}
			j++;
			s_word = -1;
		}
		i++;
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	size_t	word_count;
	size_t	len;
	char	**res;

	word_count = ft_count_words(s, c);
	len = ft_strlen(s);
	res = malloc(sizeof(char *) * (word_count + 1));
	if (!res)
		return (NULL);
	if (ft_process_split(res, s, len, c) == 1)
	{
		free(res);
		return (NULL);
	}
	res[word_count] = NULL;
	return (res);
}*/
/*
int main(void)
{
    char **result;
    const char *str = "Hello  World   This Is A Test";
    char sep = ' ';
    
    result = ft_split(str, sep);

    if (result)
    {
        for (size_t i = 0; result[i] != NULL; i++)
        {
            printf("Word %zu: %s\n", i, result[i]);
            free(result[i]); // Free each string
        }
        free(result); // Free the array of pointers
    }

    return 0;
}*/
