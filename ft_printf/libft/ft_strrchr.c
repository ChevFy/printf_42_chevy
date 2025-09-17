/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chevfy <chevfy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:36:41 by chevfy            #+#    #+#             */
/*   Updated: 2025/06/17 23:07:52 by chevfy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	check;
	char			*last;

	last = NULL;
	check = (unsigned char)c;
	while (*s != '\0')
	{
		if ((unsigned char)*s == check)
			last = (char *)s;
		s++;
	}
	if ((unsigned char)*s == check)
		last = (char *)s;
	return (last);
}
