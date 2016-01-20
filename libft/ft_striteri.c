/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 10:27:02 by zhasni            #+#    #+#             */
/*   Updated: 2014/11/11 20:55:08 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;
	int		len;

	i = 0;
	if (s != NULL && f != NULL)
	{
		len = ft_strlen (s);
		while (i < len)
		{
			(*f)(i, s);
			s++;
			i++;
		}
	}
}
