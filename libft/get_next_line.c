/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 12:50:42 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/09 11:53:02 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char		*ft_mallocat(char const *s1, char const *s2)
{
	char	*tmp;
	int		len;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	while (s1[j])
		tmp[i++] = s1[j++];
	j = 0;
	while (s2[j])
		tmp[i++] = s2[j++];
	tmp[i] = '\0';
	return (tmp);
}

static int		ft_check_line(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char		*ft_write_stock(char **line, char *src)
{
	int		i;
	char	*tmp;

	i = 0;
	*line = ft_strdup(src);
	tmp = ft_strdup(src);
	while (*src)
	{
		if (*src == '\n' || *(src + 1) == '\0')
		{
			if (*src != '\n' && *(src + 1) == '\0')
				line[0][i++] = *src;
			line[0][i] = '\0';
			i = 0;
			src++;
			while (*src)
				tmp[i++] = *src++;
			tmp[i] = '\0';
			return (tmp);
		}
		line[0][i++] = *src++;
	}
	return (tmp);
}

int				get_next_line(int const fd, char **line)
{
	static char	*tmp[10000];
	char		dst[BUFF_SIZE + 1];
	int			ret;

	ret = 0;
	if (line == NULL || fd < 0)
		return (-1);
	while ((ft_check_line(tmp[fd])) != 1)
	{
		ret = read(fd, dst, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		dst[ret] = '\0';
		tmp[fd] = ft_mallocat(tmp[fd], dst);
		if (ret == 0 && (!*tmp[fd] || !tmp[fd]))
		{
			free(tmp[fd]);
			return (0);
		}
		else if (ret == 0 && tmp[fd])
			break ;
	}
	tmp[fd] = ft_write_stock(line, tmp[fd]);
	return (1);
}
