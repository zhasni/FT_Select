/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 10:40:39 by zhasni            #+#    #+#             */
/*   Updated: 2014/11/14 10:56:10 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_swap_itoa(char *str)
{
	char	tmp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str) - 1;
	if (str[i] == '-')
		i++;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}

char		*ft_itoa(int nb)
{
	char	*tmp;
	int		i;

	if (nb == -2147483648)
		return ("-2147483648");
	i = 0;
	tmp = (char *)malloc(sizeof(char) * 12);
	if (!tmp)
		return (NULL);
	if (nb < 0)
	{
		tmp[i] = '-';
		nb = -nb;
		i++;
	}
	while (nb > 9)
	{
		tmp[i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	tmp[i] = nb + '0';
	tmp[i + 1] = '\0';
	tmp = ft_swap_itoa(tmp);
	return (tmp);
}
