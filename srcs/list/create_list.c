/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:59:00 by bfaure            #+#    #+#             */
/*   Updated: 2023/03/31 13:37:38 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap_list.h"

t_list	*make_list(char	**tab_list)
{
	size_t	i;
	int		nb;
	t_list	*following;
	t_list	*a;

	i = 0;
	while (tab_list)
	{
		nb = ft_atoi(tab_list[i]);
		if (i == 1)
			a = ft_lstnew(nb);
		else
		{
			following = ft_lstnew(nb);
			if (!following)
				return (0);
			ft_lstadd_back(&a, following);
		}
		i++;
	}
	if (i > 0)
		ft_print_list(a);
	ft_lstclear(a);
}
