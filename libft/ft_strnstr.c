/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:40:37 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/03 20:08:37 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*start;
	char	*max;
	size_t	nlen;

	nlen = ft_strlen(s2);
	max = (char *)(s1 + n);
	if (!s2 || !nlen || !s1)
		return ((char *)s1);
	start = (char *)s1;
	while ((start = ft_strchr(start, *s2)) && start <= max)
	{
		if (start + nlen <= max && !ft_strncmp(start, s2, nlen))
			return (start);
		start++;
	}
	return (NULL);
}
