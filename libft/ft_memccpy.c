/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:07:21 by zhasni            #+#    #+#             */
/*   Updated: 2014/11/13 19:22:41 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*tmp;
	const char	*source;

	i = 0;
	tmp = (char *)dest;
	source = (const char *)src;
	while (i < n)
	{
		tmp[i] = source[i];
		if (source[i] == c)
			return (tmp + (i + 1));
		i++;
	}
	return (NULL);
}
