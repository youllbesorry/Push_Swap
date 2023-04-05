/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:52:03 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/05 15:55:24 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_list	*lst;

	init_data(&data);
	if (join_arg(argc, argv, &data) == -1)
		return (-1);
	ft_printf("data.arg = %s\n", data.arg);
	if (split_args(&data) == -1)
		return (-1);
	parsing_error(&data);
	lst = make_list(&data);
	if (!lst)
		return (free_all(&data), -1);
	free_all(&data);
	if (check_multiple_same_digits(lst) == -1)
	{
		ft_printf("============================ERROR==============================\n");
		ft_putstr_fd("ERROR\nMultiple same digits found\n", 2);
		exit (0);
	}
	index_list_value(lst);
	ft_print_list(lst);
	if (check_sort(lst) == 0)
		ft_printf("List sort\n");
	else
		ft_printf("List not sort\n");
	ft_lstclear(lst);
	return (0);
}
