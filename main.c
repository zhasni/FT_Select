/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 12:11:05 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/09 23:18:00 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

const char		*ft_getenvterm(char **env)
{
	int			i;

	i = 0;
	while (env[i])
	{
		if (ft_memcmp(env[i], "TERM=", 5) == 0)
		{
			return (&env[i][5]);
		}
		i++;
	}
	return (NULL);
}

int				ft_initmodes(const char *term)
{
	if (1 == tgetent(NULL, term))
	{
		ft_getmodes(term);
		return (1);
	}
	return (0);
}

t_sel			**sel_gettab(int ac, char *av[])
{
	int			i;
	t_sel		**t;

	if (!(t = (t_sel**)malloc(sizeof(t_sel*) * ac)))
		return (NULL);
	i = 0;
	while (i < ac - 1)
	{
		if (!(t[i] = (t_sel*)malloc(sizeof(t_sel))))
			return (NULL);
		t[i]->name = ft_strdup(av[i + 1]);
		t[i]->selected = 0;
		t[i]->deleted = 0;
		t[i]->pos = 0;
		t[i]->next = 0;
		t[i]->prev = 0;
		i++;
	}
	t[i] = NULL;
	return (t);
}

int				ft_select(t_sel **t, char const *ttyname)
{
	int const	fd = open(ttyname, O_RDWR);

	if (-1 == fd)
		return (fd);
	*fd_get() = fd;
	sel_makecirc(t);
	sel_loop(t);
	ft_line_del();
	sel_results(t);
	return (0);
}

int				main(int ac, char *av[], char **environ)
{
	t_sel		**t;

	if (!ft_initmodes(ft_getenvterm(environ)))
	{
		ft_putendl("ft_select: error: TERM missing or unknown");
		return (1);
	}
	sel_switchterm(0);
	signal(SIGWINCH, sig_winch);
	signal(SIGINT, sel_hand);
	signal(SIGCONT, sig_stop);
	if (ac < 2)
		ft_putendl("usage: ./ft_select [[element1] [...] [elementn]]");
	else
	{
		t = sel_gettab(ac, av);
		if (!t)
			return (-1);
		ft_select(t, ttyname(0));
	}
	sel_switchterm(1);
	return (0);
}
