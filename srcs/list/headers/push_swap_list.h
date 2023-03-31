/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Chain_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:56:09 by bfaure            #+#    #+#             */
/*   Updated: 2023/03/28 14:56:09 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_LIST_H
# define PUSH_SWAP_LIST_H

# include "struct.h"
# include "../../../headers/push_swap.h"
# include <stdlib.h>
# include <stdio.h>

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list *lst);
void	ft_print_list(t_list *lst);
t_list	*make_list(char	**tab_list);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif