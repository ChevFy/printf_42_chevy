/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chevfy <chevfy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:33:11 by chevfy            #+#    #+#             */
/*   Updated: 2025/09/20 15:42:32 by chevfy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_ptrlen(uintptr_t n)
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

char	*ft_putptr(uintptr_t n)
{
	int		length;
	char	*hex;
	char	*base;

	base = "0123456789abcdef";
	length = ft_ptrlen(n);
	hex = (char *)malloc(sizeof(char) * (length + 1));
	if (!hex)
		return (NULL);
	hex[length] = '\0';
	if (n == 0)
		hex[0] = '0';
	while (n > 0)
	{
		hex[length - 1] = base[n % 16];
		n /= 16;
		length--;
	}
	return (hex);
}

int	ft_printptr(unsigned long long ptr)
{
	int		length;
	char	*hex;

	length = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	else
	{
		length += write(1, "0x", 2);
		hex = ft_putptr((uintptr_t)ptr);
		if (!hex)
			return (-1);
		ft_printstr(hex);
		free(hex);
		length += ft_ptrlen(ptr);
	}
	return (length);
}
