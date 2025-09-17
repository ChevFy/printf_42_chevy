/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chevfy <chevfy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:01:05 by chevfy            #+#    #+#             */
/*   Updated: 2025/07/01 14:11:56 by chevfy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*keep;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	keep = (char *)malloc(sizeof(char) * (len + 1));
	if (!keep)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		keep[i] = f(i, s[i]);
		i++;
	}
	keep[i] = '\0';
	return (keep);
}
