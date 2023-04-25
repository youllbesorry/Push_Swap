/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:40:39 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/25 15:16:14 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	check_sort(t_list *lst_a)
{
	t_list			*tmp_lst_a;
	unsigned int	tmp;

	tmp = lst_a->index;
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

void	sort(t_list **lst_a, t_list **lst_b)
{
	size_t	size;

	if (check_sort(*lst_a) != 0)
	{
		size = ft_lstsize((*lst_a));
		if (size == 2)
			s(lst_a, "sa");
		else if (size == 3)
			sort_three(lst_a);
		else if (size == 4)
			sort_four(lst_a, lst_b);
		else if (size == 5)
			sort_five(lst_a, lst_b);
		else
			radix(lst_a, lst_b);
	}
	ft_lstclear(*lst_a);
	ft_lstclear(*lst_b);
	return ;
}

void	radix(t_list **lst_a, t_list **lst_b)
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
				p(lst_a, lst_b, "pb");
			index++;
		}
		while ((*lst_b))
			p(lst_b, lst_a, "pa");
		i++;
	}
	return ;
}
