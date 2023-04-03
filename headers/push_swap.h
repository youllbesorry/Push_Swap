/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:09:37 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/03 14:58:53 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/list/headers/push_swap_list.h"
# include "../Libft/headers/libft.h"
# include "../Libft/headers/ft_printf.h"
# include "struct.h"

void	free_tab(char **tab);
void	free_all(t_data *data);
void	init_data(t_data *data);
void	parsing_error(t_data *data);

int		split_args(t_data *data);
int		join_arg(int argc, char **argv, t_data *data);

#endif