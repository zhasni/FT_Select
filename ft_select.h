/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 11:58:50 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/24 14:20:52 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft/libft.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <signal.h>

typedef struct termios	t_tios;

typedef struct			s_sel
{
	char				*name;
	int					selected;
	int					deleted;
	int					pos;
	struct s_sel		*next;
	struct s_sel		*prev;
}						t_sel;
typedef enum			e_mode
{
	M_REVERSEVIDEO,
	M_DEFAULT,
	M_CLEARLINE,
	M_CLEARSCREEN,
	M_UL_START,
	M_UL_STOP,
	M_CUR_HIDE,
	M_CUR_NORMAL,
	M_KEY_ARROWU,
	M_KEY_ARROWD
}						t_mode;

char					**ft_getmodes(const char *term);
int						ft_putc(int c);
void					ft_setmode(t_mode mode);
void					sel_results(t_sel **t);
void					ft_line_del();
t_sel					*sel_getprev(t_sel *e);
t_sel					*sel_getnext(t_sel *e);
int						sel_loop(t_sel **t);
int						sel_kbhit(t_sel **cur, int key);
void					sel_switchterm(int quitting);
void					sel_hand(int nb);
int						*ft_stopped();
void					sig_stop(int nb);
void					ft_print_revvid(const char *s);
void					ft_print_undlind(const char *s);
void					ft_print_ulrv(const char *s);
void					sel_print(t_sel *e, int current);
void					sel_prints(t_sel *e);
int						ft_initmodes(const char *term);
void					sel_makecirc(t_sel **t);
t_sel					**sel_gettab(int ac, char *av[]);
const char				*ft_getenvterm(char **env);
int						ft_tgetent(char *bp, const char *name);
int						*fd_get();
void					sig_winch(int nb);

#endif
