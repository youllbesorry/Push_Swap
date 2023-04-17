/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:40:39 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/16 16:27:30 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

size_t	index_len(t_list *lst)
{
	t_list			*tmp_lst;
	t_list			*head;
	unsigned int	tmp;
	size_t			i;
	size_t			j;

	tmp = lst->content;
	head = lst;
	ft_printf(RED"============================INDEX_LEN==========================\n"END);
	while (lst)
	{
		tmp = lst->content;
		tmp_lst = head;
		i = 1;
		j = 0;
		while (tmp_lst)
		{
			while (i < 4000000000)
			{
				if (tmp >= i)
					j++;
				i *= 10;
			}
			tmp_lst = tmp_lst->next;
		}
		lst = lst->next;
	}
	return (j);
}

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
