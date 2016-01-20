/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 10:51:29 by zhasni            #+#    #+#             */
/*   Updated: 2014/11/23 18:19:21 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*dst;

	i = 0;
	if (s && f)
	{
		len = ft_strlen(s);
		dst = (char *)malloc(sizeof(char) * len + 1);
		if (!dst)
			return (NULL);
		while (s[i])
		{
			dst[i] = (*f)(s[i]);
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
