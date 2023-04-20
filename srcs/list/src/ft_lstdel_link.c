/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:29:03 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/20 14:33:50 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap_list.h"


void	ft_lstdel_link(t_list *lst, size_t n)
{
	//t_list	*tmp_lst;
	size_t	i;

	i = 0;
	ft_printf(RED"============================DEL================================\n"END);
	//tmp_lst = (*lst);
	while (i < n)
	{
		ft_printf("n = %i, i = %i, content = %i, index = %i\n", n, i, lst->content, lst->index);
		lst = lst->next;
		i++;
	}
	//free (tmp_lst);
	while (lst)
	{
		ft_printf("i = %i, content %d index [%d]\n", i, lst->content, lst->index);
		lst = lst->next;
		i++;
	}
	return ;
}
