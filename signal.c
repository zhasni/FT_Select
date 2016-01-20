/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 12:11:05 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/09 23:20:12 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			sel_hand(int nb)
{
	(void)nb;
	ft_setmode(M_CLEARSCREEN);
	sel_switchterm(1);
	exit(0);
}

int				*ft_stopped(void)
{
	static int	stopped;

	return (&stopped);
}

void			sig_winch(int nb)
{
	int const	width = tgetnum("co");
	int const	height = tgetnum("li");

	(void)nb;
	ft_line_del();
	if (height < 3 || width < 10)
	{
		ft_line_del();
		ft_putstr_fd("...", *fd_get());
	}
}

void			sig_stop(int nb)
{
	if (nb == SIGCONT)
	{
		ft_setmode(M_CLEARSCREEN);
		sel_switchterm(0);
	}
	else
	{
		ft_putendl("stop");
		*ft_stopped() = 1;
	}
}

void			sel_makecirc(t_sel **t)
{
	int			i;

	i = 0;
	while (t[i])
	{
		t[i]->next = t[i + 1];
		if (i > 0)
			t[i]->prev = t[i - 1];
		i++;
	}
	i--;
	t[0]->prev = t[i];
	t[i]->next = t[0];
}
