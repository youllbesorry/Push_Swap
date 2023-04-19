/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:40:39 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/19 17:12:00 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	check_sort(t_list *lst_a)
{
	t_list			*tmp_lst_a;
	unsigned int	tmp;

	tmp = lst_a->index;
	ft_printf(RED"============================CHECK_SORT=========================\n"END);
	while (lst_a)
	{
		tmp = lst_a->index;
		tmp_lst_a = lst_a;
		while (tmp_lst_a)
		{
			if (tmp > tmp_lst_a->index)
				return (-1);
			tmp_lst_a = tmp_lst_a->next;
		}
		lst_a = lst_a->next;
	}
	return (0);
}

void	bit_shifting(t_list	*lst_a)
{
	// int	tmp;
	t_list	*lst_b;

	lst_b = NULL;
	// tmp = lst_a->index;
	// ft_printf("tmp = %i\n", tmp);
	// tmp = tmp >> 1;
	// ft_printf("tmp bitshift = %i\n", tmp);
	s(lst_a);
	ft_print_list(lst_a);
	p(lst_b, lst_a);
	ft_print_list(lst_a);
	//ft_print_list(lst_b);
	return ;
}
