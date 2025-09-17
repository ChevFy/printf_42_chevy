/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chevfy <chevfy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:48:08 by chevfy            #+#    #+#             */
/*   Updated: 2025/06/22 17:18:56 by chevfy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_digit(int n)
{
	size_t	count;
	long	nb;

	nb = (long)n;
	count = 0;
	if (nb <= 0)
	{
		nb *= -1;
		count++;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*keep;
	size_t	i;
	size_t	len;
	long	nb;

	nb = (long)n;
	len = ft_count_digit(n);
	keep = (char *)malloc(sizeof(char) * (len + 1));
	if (keep == NULL)
		return (NULL);
	keep[len] = '\0';
	if (nb == 0)
		keep[0] = '0';
	if (nb < 0)
	{
		keep[0] = '-';
		nb *= -1;
	}
	i = len - 1;
	while (nb > 0)
	{
		keep[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (keep);
}
// #include <stdio.h>
// int main(void)
// {
// 	char *s1 , *s2 , *s3 , *s4 , *s5;

// 	s1 = ft_itoa(0);
// 	printf("itoa(0): %s\n", s1);

// 	s2 = ft_itoa(42);
// 	printf("itoa(42): %s\n", s2);

// 	s3 = ft_itoa(-42);
// 	printf("itoa(-42): %s\n", s3);

// 	s4 = ft_itoa(-2147483648);
// 	printf("itoa(INT_MIN): %s\n", s4);

// 	s5 = ft_itoa(2147483647);
// 	printf("itoa(INT_MAX): %s\n", s5);

// 	return (0);
// }
