/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chevfy <chevfy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:32:16 by chevfy            #+#    #+#             */
/*   Updated: 2025/07/01 14:52:09 by chevfy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int num1, int num2)
{
	int	i;
	int	j;

	j = num1;
	i = 1;
	while (i < num2)
	{
		num1 = num1 * j;
		i++;
	}
	return (num1);
}

int	ft_countdigit(int num)
{
	int	i;

	i = 1;
	while (num / 10 != 0)
	{
		i++;
		num = num / 10;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	i;
	int	j;
	int	l;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	j = n;
	i = ft_countdigit(n) - 1;
	if (j < 0)
	{
		j = j * (-1);
		ft_putchar_fd('-', fd);
	}
	while (i != 0)
	{
		l = j / (ft_pow(10, i));
		ft_putchar_fd((l % 10) + '0', fd);
		i--;
	}
	ft_putchar_fd((j % 10) + '0', fd);
}
