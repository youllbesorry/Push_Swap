/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:40:39 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/13 16:31:50 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	check_sort(t_list *lst)
{
	t_list			*tmp_lst;
	unsigned int	tmp;

	tmp = lst->index;
	ft_printf(RED"============================CHECK_SORT=========================\n"END);
	while (lst)
	{
		tmp = lst->index;
		tmp_lst = lst;
		while (tmp_lst)
		{
			if (tmp > tmp_lst->index)
				return (-1);
			tmp_lst = tmp_lst->next;
		}
		lst = lst->next;
	}
	return (0);
}
