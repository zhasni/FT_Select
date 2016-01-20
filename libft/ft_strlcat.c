/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:51:01 by zhasni            #+#    #+#             */
/*   Updated: 2014/11/23 19:52:29 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	char	*tmp;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	tmp = dst;
	if (len_dst + 1 > size)
		return (len_src + size);
	else
	{
		ft_memcpy(tmp + len_dst, src, sizeof(char) * (size - len_dst - 1));
		dst[size - 1] = '\0';
	}
	return (len_dst + len_src);
}
