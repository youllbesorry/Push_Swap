/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:52:03 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/27 15:16:38 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_list	*lst_a;
	t_list	*lst_b;

	lst_b = NULL;
	if (join_arg(argc, argv, &data) == -1)
		return (-1);
	if (split_args(&data) == -1)
		return (-1);
	parsing_error(&data, &lst_a, 0);
	lst_a = make_list_a(&data);
	if (!lst_a)
		return (free_all(&data), -1);
	parsing_error(&data, &lst_a, 1);
	free_all(&data);
	index_list_value(lst_a);
	sort(&lst_a, &lst_b);
	return (0);
}
