/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 09:11:05 by zhasni            #+#    #+#             */
/*   Updated: 2014/11/23 18:07:08 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*src;
	size_t		i;

	i = 0;
	if (s && n > 0)
	{
		src = (const char *)s;
		while (i < n)
		{
			if ((unsigned char)src[i] == (unsigned char)c)
				return ((void *)src + i);
			i++;
		}
	}
	return (NULL);
}
