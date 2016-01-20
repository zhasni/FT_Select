/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 12:11:05 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/19 12:05:26 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_print_revvid(const char *s)
{
	ft_setmode(M_REVERSEVIDEO);
	ft_putendl_fd(s, *fd_get());
	ft_setmode(M_DEFAULT);
}

void		ft_print_undlind(const char *s)
{
	ft_setmode(M_UL_START);
	ft_putendl_fd(s, *fd_get());
	ft_setmode(M_UL_STOP);
}

void		ft_print_ulrv(const char *s)
{
	ft_setmode(M_REVERSEVIDEO);
	ft_setmode(M_UL_START);
	ft_putendl_fd(s, *fd_get());
	ft_setmode(M_UL_STOP);
	ft_setmode(M_DEFAULT);
}

void		sel_print(t_sel *e, int current)
{
	if (e->selected && current && e->deleted == 0)
		ft_print_ulrv(e->name);
	else if (e->selected && e->deleted == 0)
		ft_print_revvid(e->name);
	else if (current && e->deleted == 0)
		ft_print_undlind(e->name);
	else if (e->deleted != 1)
		ft_putendl_fd(e->name, *fd_get());
}

void		sel_prints(t_sel *e)
{
	t_sel	*next;

	next = sel_getnext(e);
	ft_setmode(M_CLEARSCREEN);
	sel_print(e, e->pos);
	while (next != e)
	{
		sel_print(next, next->pos);
		next = next->next;
	}
}
