/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:52:03 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/19 14:37:19 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_list	*lst_a;

	init_data(&data);
	if (join_arg(argc, argv, &data) == -1)
		return (-1);
	ft_printf("data.arg = %s\n", data.arg);
	if (split_args(&data) == -1)
		return (-1);
	parsing_error(&data);
	lst_a = make_list_a(&data);
	if (!lst_a)
		return (free_all(&data), -1);
	free_all(&data);
	if (check_multiple_same_digits(lst_a) == -1)
	{
		ft_printf(RED"============================ERROR==============================\n"END);
		ft_putstr_fd("ERROR\nMultiple same digits found\n", 2);
		exit (0);
	}
	index_list_value(lst_a);
	ft_print_list(lst_a);
	if (check_sort(lst_a) == 0)
		ft_printf("List sort\n");
	else
		ft_printf("List not sort\n");
	data.lst_a_size = lst_size(lst_a);
	ft_printf("lst_a size = %i\n", data.lst_a_size);
	bit_shifting(lst_a);
	ft_lstclear(lst_a);
	return (0);
}
