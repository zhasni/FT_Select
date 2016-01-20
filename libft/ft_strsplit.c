/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 15:24:10 by zhasni            #+#    #+#             */
/*   Updated: 2014/11/23 19:18:49 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strtri(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	int		size;
	char	*tmp;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[len] == c)
		len--;
	while (s[i] == c)
		i++;
	size = len - i;
	if (size < 0)
		size = 0;
	tmp = (char *)malloc(sizeof(char) * size + 1);
	if (!tmp)
		return (NULL);
	while (i <= len)
		tmp[j++] = s[i++];
	tmp[j] = '\0';
	return (tmp);
}

static char	**ft_split(char *tmp, char **dst, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (tmp[i] == '\0')
		dst[j] = NULL;
	while (*tmp)
	{
		while (*tmp == c)
		{
			if (*(tmp + 1) != c)
			{
				dst[j++][i] = '\0';
				i = 0;
			}
			tmp++;
		}
		dst[j][i++] = *tmp++;
	}
	dst[j + 1] = NULL;
	return (dst);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**dst;
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	dst = (char **)malloc(sizeof(char *) * len);
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = (char *)malloc(sizeof(char) * len);
		if (!dst[i])
			return (NULL);
		i++;
	}
	tmp = ft_strtri(s, c);
	dst = ft_split(tmp, dst, c);
	return (dst);
}
