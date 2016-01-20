/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 23:23:42 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/09 23:25:55 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int					*fd_get(void)
{
	static int		fd;

	return (&fd);
}

int					ft_putc(int c)
{
	return ((int)write(*fd_get(), &c, 1));
}

void				ft_setmode(t_mode mode)
{
	char			**modes;

	modes = ft_getmodes(NULL);
	tputs(modes[mode], 0, ft_putc);
}

void				ft_line_del(void)
{
	ft_setmode(M_CLEARSCREEN);
}
