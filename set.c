/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 23:21:48 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/24 14:20:17 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				sel_results(t_sel **t)
{
	int				i;
	int				cnt;

	cnt = 0;
	i = 0;
	while (t[i])
	{
		if (t[i]->selected && !t[i]->deleted)
		{
			if (cnt)
				ft_putchar(' ');
			cnt++;
			ft_putstr(t[i]->name);
		}
		i++;
	}
	ft_putchar('\n');
}

t_sel				*sel_getprev(t_sel *e)
{
	t_sel	*start;

	start = e;
	e = e->prev;
	while (e->deleted)
	{
		if (e == start)
			return (NULL);
		e = e->prev;
	}
	return (e);
}

t_sel				*sel_getnext(t_sel *e)
{
	t_sel	*start;

	start = e;
	e = e->next;
	while (e->deleted)
	{
		if (e == start)
			return (NULL);
		e = e->next;
	}
	return (e);
}

void				sel_switchterm(int quitting)
{
	static t_tios	saved;
	t_tios			n;

	(void)n;
	if (quitting)
	{
		tcsetattr(0, TCSAFLUSH, &saved);
		ft_setmode(M_CUR_NORMAL);
	}
	else
	{
		tcgetattr(0, &saved);
		n = saved;
		n.c_lflag &= ~(ICANON | ECHO);
		n.c_cc[VMIN] = 1;
		n.c_cc[VTIME] = 0;
		tcsetattr (0, TCSAFLUSH, &n);
		ft_setmode(M_CUR_HIDE);
	}
}
