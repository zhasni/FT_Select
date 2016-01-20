/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 16:47:24 by zhasni            #+#    #+#             */
/*   Updated: 2014/11/13 19:31:40 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*begin_lst;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	begin_lst = tmp;
	while (lst->next != NULL)
	{
		tmp->next = f(lst->next);
		if (tmp == NULL)
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (begin_lst);
}
