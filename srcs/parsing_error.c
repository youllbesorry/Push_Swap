/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 08:57:45 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/26 16:40:59 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	parsing_error(t_data *data, t_list **lst_a, int n)
{
	if (n == 0)
	{
		if (check_val_args(data) == -1 || check_weird_args(data) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
	}
	else if (n == 1)
	{
		if (check_multiple_same_digits(*lst_a) == -1)
		{
			free_all(data);
			ft_putstr_fd("Error\n", 2);
			exit (0);
		}
	}
	return ;
}
