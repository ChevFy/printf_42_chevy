/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chevfy <chevfy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:33:11 by chevfy            #+#    #+#             */
/*   Updated: 2025/09/17 17:36:50 by chevfy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	char	*num;
	int		lenght;

	lenght = 0;
	num = ft_itoa(n);
	lenght = ft_printstr(num);
	free(num);
	return (lenght);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
