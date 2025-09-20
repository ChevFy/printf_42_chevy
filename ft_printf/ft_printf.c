/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chevfy <chevfy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:49:55 by chevfy            #+#    #+#             */
/*   Updated: 2025/09/20 15:37:44 by chevfy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	char	ch;

	ch = (char)c;
	write(1, &ch, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_printchar(va_arg(args, int));
	if (format == 's')
		length += ft_printstr(va_arg(args, char *));
	if (format == 'd' || format == 'i')
		length += ft_printnbr(va_arg(args, int));
	if (format == 'p')
		length += ft_printptr(va_arg(args, unsigned long long));
	if (format == 'u')
		length += ft_print_unsigned(va_arg(args, unsigned int));
	if (format == 'x' || format == 'X')
		length += ft_print_hex(va_arg(args, unsigned int), format);
	if (format == '%')
		length += ft_printpercent();
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		length;
	int		i;

	if (!str)
		return (0);
	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			length += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (length);
}
