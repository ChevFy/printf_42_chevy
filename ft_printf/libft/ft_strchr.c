/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chevfy <chevfy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:36:41 by chevfy            #+#    #+#             */
/*   Updated: 2025/06/18 01:35:38 by chevfy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	check;

	check = (unsigned char)c;
	while (*s != '\0')
	{
		if ((unsigned char)*s == check)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)*s == check)
		return ((char *)s);
	return (NULL);
}
