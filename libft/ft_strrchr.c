/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:44:10 by zhasni            #+#    #+#             */
/*   Updated: 2014/11/23 17:16:25 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			j = i;
		i++;
	}
	if (s[0] == c && j == 0)
		return ((char *)s);
	if (j > 0 && c != 0)
		return ((char *)s + j);
	else if (j >= 0 && (c == 0 || s[0] == c))
		return ((char *)s + i);
	return (NULL);
}
