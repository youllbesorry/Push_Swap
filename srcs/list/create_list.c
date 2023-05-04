/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:59:00 by bfaure            #+#    #+#             */
/*   Updated: 2023/05/04 10:04:58 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap_list.h"

t_list	*make_list_a(t_data *data)
{
	ssize_t		i;
	long long	nb;
	t_list		*following;
	t_list		*a;

	i = -1;
	a = NULL;
	while (data->tab_list[++i])
	{
		nb = overflow_control(data, a, i);
		if (i == 0)
		{
			a = ft_lstnew(nb);
			if (!a)
				return (ft_putstr_fd("Error\n", 2), NULL);
		}
		else
		{
			following = ft_lstnew(nb);
			if (!following)
				return (ft_lstclear(a), NULL);
			ft_lstadd_back(&a, following);
		}
	}
	return (a);
}

void	index_list_value(t_list *lst)
{
	t_list	*tmp_lst;
	t_list	*head;
	int		tmp;
	int		index;

	tmp = lst->content;
	head = lst;
	while (lst)
	{
		index = 0;
		tmp = lst->content;
		tmp_lst = head;
		while (tmp_lst)
		{
			if (tmp > tmp_lst->content)
				index++;
			tmp_lst = tmp_lst->next;
		}
		lst->index = index;
		lst = lst->next;
	}
	return ;
}
