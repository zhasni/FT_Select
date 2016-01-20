/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 12:11:05 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/24 14:19:45 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char				**ft_getmodes(const char *term)
{
	static char		*ret[20];

	if (term)
	{
		if (tgetent(NULL, term) == 1)
		{
			ret[M_DEFAULT] = tgetstr("me", NULL);
			ret[M_REVERSEVIDEO] = tgetstr("mr", NULL);
			ret[M_CLEARSCREEN] = tgetstr("cl", NULL);
			ret[M_CLEARLINE] = tgetstr("ce", NULL);
			ret[M_UL_START] = tgetstr("us", NULL);
			ret[M_UL_STOP] = tgetstr("ue", NULL);
			ret[M_CUR_HIDE] = tgetstr("vi", NULL);
			ret[M_CUR_NORMAL] = tgetstr("ve", NULL);
			ret[M_KEY_ARROWU] = tgetstr("ku", NULL);
			ret[M_KEY_ARROWD] = tgetstr("kd", NULL);
		}
	}
	return (ret);
}

int					sel_kbhit_bis(t_sel **cur, int key)
{
	if (key == 0x20)
	{
		(*cur)->pos = 0;
		(*cur)->selected = !(*cur)->selected;
		*cur = sel_getnext(*cur);
		(*cur)->pos = 1;
	}
	else if (key == 0x0a)
		return (0);
	else if (key == 27)
	{
		ft_setmode(M_CLEARSCREEN);
		sel_switchterm(1);
		exit(0);
	}
	return (1);
}

int					sel_kbhit(t_sel **cur, int key)
{
	if (key == 0x415b1b)
	{
		(*cur)->pos = 0;
		*cur = sel_getprev(*cur);
		(*cur)->pos = 1;
	}
	else if (key == 0x425b1b)
	{
		(*cur)->pos = 0;
		*cur = sel_getnext(*cur);
		(*cur)->pos = 1;
	}
	else if (key == 0x7f)
	{
		(*cur)->pos = 0;
		(*cur)->deleted = 1;
		if (NULL == (*cur = sel_getnext(*cur)))
			return (0);
		(*cur)->pos = 1;
	}
	else
		return (sel_kbhit_bis(cur, key));
	return (1);
}

int					sel_loop(t_sel **t)
{
	t_sel			*cur;
	ssize_t			er;
	int				key;

	cur = t[0];
	cur->pos = 1;
	while (cur)
	{
		sel_prints(t[0]);
		key = 0;
		er = read(0, &key, sizeof(key));
		if (er < 1 && *ft_stopped() == 1)
			return (0);
		if (!sel_kbhit(&cur, key))
			break ;
	}
	return (0);
}
