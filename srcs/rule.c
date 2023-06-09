/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:50:15 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/24 11:21:26 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	s(t_list **lst, char *rule)
{
	t_list			*tmp_lst;

	if (!(*lst) || !lst)
		return ;
	tmp_lst = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	tmp_lst->next = (*lst);
	(*lst) = tmp_lst;
	ft_printf("%s\n", rule);
	return ;
}

void	p(t_list **lst_from, t_list **lst_to, char *rule)
{
	t_list	*tmp_lst;

	if (!(*lst_from) || !lst_from)
		return ;
	tmp_lst = (*lst_from);
	(*lst_from) = (*lst_from)->next;
	tmp_lst->next = (*lst_to);
	(*lst_to) = tmp_lst;
	ft_printf("%s\n", rule);
	return ;
}

void	r(t_list **lst, char *rule)
{
	t_list	*tmp_lst;
	t_list	*last_lst;

	tmp_lst = (*lst);
	(*lst) = (*lst)->next;
	last_lst = ft_lstlast(*lst);
	tmp_lst->next = NULL;
	last_lst->next = tmp_lst;
	ft_printf("%s\n", rule);
	return ;
}

void	rr(t_list **lst, char *rule)
{
	t_list	*tmp_lst;
	t_list	*last_lst;

	tmp_lst = (*lst);
	while (tmp_lst->next->next)
		tmp_lst = tmp_lst->next;
	last_lst = tmp_lst->next;
	tmp_lst->next = NULL;
	last_lst->next = (*lst);
	(*lst) = last_lst;
	ft_printf("%s\n", rule);
	return ;
}
