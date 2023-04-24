/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:09:37 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/24 16:28:58 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define END "\033[0m"
# define RED "\033[1;31m"

# include "../srcs/list/headers/push_swap_list.h"
# include "../Libft/headers/libft.h"
# include "../Libft/headers/ft_printf.h"
# include "struct.h"
# include "limits.h"

void	free_tab(char **tab);
void	free_all(t_data *data);
void	init_data(t_data *data);
void	sort_three(t_list **lst_a);
void	parsing_error(t_data *data);
void	s(t_list **lst, char *rule);
void	r(t_list **lst, char *rule);
void	rr(t_list **lst, char *rule);
void	index_list_value(t_list *lst);
void	sort(t_list **lst_a, t_list **lst_b);
void	radix(t_list **lst_a, t_list **lst_b);
void	sort_four(t_list **lst_a, t_list **lst_b);
void	sort_five(t_list **lst_a, t_list **lst_b);
void	p(t_list **lst_from, t_list **lst_to, char *rule);

int		check_sort(t_list *lst);
int		split_args(t_data *data);
int		check_val_args(t_data *data);
int		check_weird_args(t_data *data);
int		check_multiple_same_digits(t_list *list);
int		join_arg(int argc, char **argv, t_data *data);

#endif