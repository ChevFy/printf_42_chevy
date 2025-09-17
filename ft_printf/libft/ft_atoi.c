/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chevfy <chevfy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:50:47 by chevfy            #+#    #+#             */
/*   Updated: 2025/06/16 15:25:17 by chevfy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_skip_space(const char *nb)
{
	while (*nb == ' ' || (*nb >= 9 && *nb <= 13))
		nb++;
	return ((char *)nb);
}

int	ft_atoi(const char *nb)
{
	char	*n;
	int		result;
	int		sign;

	n = ft_skip_space(nb);
	result = 0;
	sign = 1;
	if (*n == '-' || *n == '+')
	{
		if (*n == '-')
			sign *= -1;
		n++;
	}
	while (*n >= '0' && *n <= '9')
	{
		result = (result * 10) + (*n - '0');
		n++;
	}
	return (sign * result);
}
