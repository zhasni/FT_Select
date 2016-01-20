/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:31:51 by zhasni            #+#    #+#             */
/*   Updated: 2014/11/08 11:15:02 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
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
		i++;
	}
	return ((void *)tmp);
}
