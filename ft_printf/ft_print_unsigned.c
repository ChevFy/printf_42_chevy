/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chevfy <chevfy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:33:05 by chevfy            #+#    #+#             */
/*   Updated: 2025/09/19 19:06:49 by chevfy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_numlen(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_numlen(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	if (n == 0)
		num[0] = '0';
	while (n != 0)
	{
		num[len - 1] = (n % 10) + '0';
		len--;
		n /= 10;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int n)
{
	int		length;
	char	*num;

	length = 0;
	if (n == 0)
		return (write(1, "0", 1));
	num = ft_uitoa(n);
	if (!num)
		return (0);
	length += ft_printstr(num);
	free(num);
	return (length);
}
