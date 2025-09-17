/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chevfy <chevfy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:56:01 by chevfy            #+#    #+#             */
/*   Updated: 2025/06/22 16:37:14 by chevfy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	sublen;
	char	*keep;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_is_in_set(s1[i], set))
		i++;
	j = len;
	while (j > i && ft_is_in_set(s1[j - 1], set))
		j--;
	sublen = j - i;
	keep = (char *)malloc(sizeof(char) * (sublen + 1));
	if (!keep)
		return (NULL);
	ft_memcpy(keep, s1 + i, sublen);
	keep[sublen] = '\0';
	return (keep);
}

// #include <stdio.h>
// void	test(char const *s1, char const *set)
// {
// 	char *result = ft_strtrim(s1, set);
// 	printf("Input:    \"%s\"\n", s1);
// 	printf("TrimSet:  \"%s\"\n", set);
// 	printf("Output:   \"%s\"\n", result);
// 	printf("--------------------------\n");
// 	free(result);
// }

// int	main(void)
// {
// 	test("   Hello World   ", " ");
// 	test("***42Bangkok***", "*");
// 	test("\n\nLine\n", "\n");
// 	test("xxtrimxx", "x");
// 	test("abcHelloabcabc", "abc");
// 	test("NoTrimHere", "");
// 	test("", " ");
// 	test("     ", " ");
// 	test("   \n\tHello\t\n   ", " \n\t");
// 	test("Hi", "Hi");  // ตัดหมด เหลือ ""
// 	test(NULL, " ");  // ต้องเช็คในโค้ดหลักว่า null-safe หรือเปล่า

// 	return (0);
// }
