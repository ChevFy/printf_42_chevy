/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf _hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chevfy <chevfy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:32:41 by chevfy            #+#    #+#             */
/*   Updated: 2025/09/18 17:23:08 by chevfy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

int	ft_hexlen(unsigned int n)
{
	int	length;

	if (n == 0)
		return (1);
	length = 0;
	while (n != 0)
	{
		length++;
		n /= 16;
	}
	return (length);
}

char	*ft_puthex(unsigned int n, const char format)
{
	char	*hex;
	int		length;
	char	*base;

	length = ft_hexlen(n);
	hex = (char *)malloc(sizeof(char) * (length + 1));
	if (!hex)
		return (NULL);
	hex[length] = '\0';
	if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	if (n == 0)
		hex[0] = '0';
	while (n != 0)
	{
		hex[length - 1] = base[n % 16];
		n /= 16;
		length--;
	}
	return (hex);
}

int	ft_print_hex(unsigned int n, const char format)
{
	char	*hex;
	int		length;

	if (n == 0)
		return (write(1, "0", 1));
	hex = ft_puthex(n, format);
	if (!hex)
		return (0);
	length = ft_printstr(hex);
	free(hex);
	return (length);
}
