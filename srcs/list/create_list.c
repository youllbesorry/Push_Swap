/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:59:00 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/20 18:44:09 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap_list.h"

t_list	*make_list_a(t_data *data)
{
	size_t		i;
	long long	nb;
	t_list		*following;
	t_list		*a;

	i = 0;
	while (data->tab_list[i])
	{
		nb = ft_atoll(data->tab_list[i]);
		if (nb > 2147483647 || nb < -2147483648)
			return (ft_lstclear(a),
				ft_putstr_fd("ERROR\nInt overflow\n", 2), NULL);
		if (i == 0)
			a = ft_lstnew(nb);
		else
		{
			following = ft_lstnew(nb);
			if (!following)
				return (ft_lstclear(a), NULL);
			ft_lstadd_back(&a, following);
		}
		i++;
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
	//ft_printf(RED"============================INDEX==============================\n"END);
	while (lst)
	{
		index = 0;
		tmp = lst->content;
		tmp_lst = head;
		//ft_printf("content tmp %i\n", tmp);
		while (tmp_lst)
		{
			//ft_printf("content tmp_lst->content %d\n", tmp_lst->content);
			if (tmp > tmp_lst->content)
				index++;
			tmp_lst = tmp_lst->next;
		}
		lst->index = index;
		lst = lst->next;
	}
	return ;
}
