/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:40:36 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/24 16:25:21 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_three(t_list **lst_a)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;

	a = (*lst_a)->index;
	b = (*lst_a)->next->index;
	c = (*lst_a)->next->next->index;
	if (a < b && b > c && c > a)
	{
		rr(lst_a, "rra");
		s(lst_a, "sa");
	}
	else if (a > b && b > c && c < a)
	{
		s(lst_a, "sa");
		rr(lst_a, "rra");
	}
	else if (a < b && b > c && c < a)
		rr(lst_a, "rra");
	else if (a > b && b < c && c > a)
		s(lst_a, "sa");
	else if (a > b && b < c && c < a)
		r(lst_a, "ra");
}

void	sort_four(t_list **lst_a, t_list **lst_b)
{
	p(lst_a, lst_b, "pb");
	sort_three(lst_a);
	p(lst_b, lst_a, "pa");
	if ((*lst_a)->index == 1)
		s(lst_a, "sa");
	else if ((*lst_a)->index == 2)
	{
		rr(lst_a, "rra");
		s(lst_a, "sa");
		rr(lst_a, "rra");
		rr(lst_a, "rra");
	}
	else if ((*lst_a)->index == 3)
		r(lst_a, "ra");
	return ;
}

void	sort_five(t_list **lst_a, t_list **lst_b)
{
	size_t	i;

	i = 0;
	while (i != 2)
	{
		if ((*lst_a)->index == 0 || (*lst_a)->index == 1)
		{
			p(lst_a, lst_b, "pb");
			i++;
		}
		else
			r(lst_a, "ra");
	}
	sort_three(lst_a);
	p(lst_b, lst_a, "pa");
	p(lst_b, lst_a, "pa");
	return ;
}
