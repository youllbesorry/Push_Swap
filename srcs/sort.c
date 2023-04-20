/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:40:39 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/20 18:43:43 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	check_sort(t_list *lst_a)
{
	t_list			*tmp_lst_a;
	unsigned int	tmp;

	tmp = lst_a->index;
	//ft_printf(RED"============================CHECK_SORT=========================\n"END);
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

void	bit_shifting(t_list	**lst_a, t_list **lst_b)
{
	size_t			i;
	size_t			size;
	size_t			index;

	i = 0;
	size = ft_lstsize(*lst_a) - 1;
	while (check_sort(*lst_a) != 0)
	{
		index = 0;
		while (index <= size)
		{
			if (((*lst_a)->index >> i) % 2 == 1)
				r(lst_a, "ra");
			else
				p(lst_a, lst_b, "rb");
			index++;
		}
		while ((*lst_b))
			p(lst_b, lst_a, "pa");
		i++;
	}
	return ;
}
