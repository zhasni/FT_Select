/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:57:47 by zhasni            #+#    #+#             */
/*   Updated: 2014/11/23 18:12:41 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp;

	if (src && dest)
	{
		tmp = (char *)malloc(sizeof(char) * ft_strlen((const char *)src));
		if (!tmp)
			return (NULL);
		ft_memcpy(tmp, src, n);
		ft_memcpy(dest, tmp, n);
	}
	return (dest);
}
