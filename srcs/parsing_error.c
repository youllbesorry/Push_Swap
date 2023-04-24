/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 08:57:45 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/24 11:25:29 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	parsing_error(t_data *data)
{
	if (check_val_args(data) == -1 || check_weird_args(data) == -1)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(0);
	}
	return ;
}
