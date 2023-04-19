/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:50:15 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/19 17:12:07 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	s(t_list *lst)
{
	unsigned int	tmp_index;
	t_list			*tmp_lst;

	ft_print_list(lst);
	ft_printf(RED"============================PUSH===============================\n"END);
	tmp_lst = lst;
	tmp_index = lst->index;
	ft_printf("tmp_index = %i\n", tmp_index);
	tmp_lst = tmp_lst->next;
	ft_printf("tmp_lst->index = %i\n", tmp_lst->index);
	ft_printf("content %d index [%d]\n", lst->content, lst->index);
	lst->index = tmp_lst->index;
	ft_printf("content %d index [%d]\n", lst->content, lst->index);
	lst = lst->next;
	ft_printf("content %d index [%d]\n", lst->content, lst->index);
	lst->index = tmp_index;
	ft_printf("content %d index [%d]\n", lst->content, lst->index);
	return ;
}

void	p(t_list *lst_1, t_list *lst_2)
{
	t_list	*tmp_lst;

	// if (!lst_1->content)
	// 	return ;
	tmp_lst = lst_1;
	lst_1 = lst_1->next;
	tmp_lst->next = lst_2;
	lst_2 = tmp_lst;
	return ;
}
