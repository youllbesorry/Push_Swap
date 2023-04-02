/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:52:03 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/02 10:14:22 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	if (join_arg(argc, argv, &data) == -1)
		return (-1);
	ft_printf("data.arg = %s\n", data.arg);
	if (split_args(&data) == -1)
		return (-1);
	if (!make_list(&data))
		return (free_all(&data), -1);
	free_all(&data);
	return (0);
}
