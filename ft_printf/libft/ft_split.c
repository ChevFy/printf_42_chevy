/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chevfy <chevfy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:10:06 by chevfy            #+#    #+#             */
/*   Updated: 2025/06/22 16:41:20 by chevfy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_word(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	*ft_str_add(char const *s, size_t start, size_t end)
{
	char	*substr;
	size_t	i;

	substr = (char *)malloc((end - start + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (start < end)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

char	**ft_split_core(char const *s, char c, char **result)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			result[j++] = ft_str_add(s, start, i);
		}
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (s == NULL)
		return (NULL);
	result = (char **)malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	return (ft_split_core(s, c, result));
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	**words = ft_split("  hello world 2222d sdf ", ' ');
// 	int		i = 0;

// 	while (words[i])
// 	{
// 		printf("word[%d]: %s\n", i, words[i]);
// 		free(words[i]);
// 		i++;
// 	}
// 	free(words);
// 	return (0);
// }