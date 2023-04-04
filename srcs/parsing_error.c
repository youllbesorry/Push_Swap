/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 08:57:45 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/04 08:58:00 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	parsing_error(t_data *data)
{
	int	error;

	error = check_val_args(data);
	if (error == -1)
	{
		ft_printf("============================ERROR==============================\n");
		ft_putstr_fd("ERROR\nA alone sign or multiple "
			"consecutive sign was found\n", 2);
		exit(0);
	}
	if (error == -2)
	{
		ft_printf("============================ERROR==============================\n");
		ft_putstr_fd("ERROR\nA non-digital char was found\n", 2);
		exit(0);
	}
	error = check_weird_args(data);
	if (error == -1)
	{
		ft_printf("============================ERROR==============================\n");
		ft_putstr_fd("ERROR\nA sign was found inside of an arg\n", 2);
		exit(0);
	}
	if (error == -2)
	{
		ft_printf("============================ERROR==============================\n");
		ft_putstr_fd("ERROR\nMore than 1 sign was found in 1 arg\n", 2);
		exit(0);
	}
	return ;
}