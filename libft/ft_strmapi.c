/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 11:43:56 by zhasni            #+#    #+#             */
/*   Updated: 2014/11/23 17:15:59 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*dst;

	i = 0;
	if (s && f)
	{
		len = ft_strlen(s);
		dst = ft_strnew(len);
		while (s[i])
		{
			dst[i] = (*f)(i, s[i]);
			i++;
		}
		return (dst);
	}
	return (NULL);
}
