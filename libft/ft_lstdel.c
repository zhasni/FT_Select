/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:40:52 by zhasni            #+#    #+#             */
/*   Updated: 2014/11/23 20:13:05 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*new;

	if (!alst || !*alst)
		return ;
	list = (*alst);
	new = (*alst)->next;
	ft_lstdelone(&list, del);
	if (new)
		ft_lstdel(&new, del);
	*alst = NULL;
}
