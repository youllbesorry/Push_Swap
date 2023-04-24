/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 08:57:45 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/21 14:20:08 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	parsing_error(t_data *data)
{
	int	error;

	error = check_val_args(data);
	if (error == -1)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(0);
	}
	error = check_weird_args(data);
	if (error == -1)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(0);
	}
	return ;
}
