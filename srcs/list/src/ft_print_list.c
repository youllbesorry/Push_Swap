/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:05:04 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/01 22:13:13 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap_list.h"

void	ft_print_list(t_list *lst)
{
	ft_printf("============================LIST===============================\n");
	while (lst)
	{
		ft_printf("content %d index [%d]\n", lst->content, lst->index);
		lst = lst->next;
	}
	return ;
}
