/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:52:03 by bfaure            #+#    #+#             */
/*   Updated: 2023/03/30 19:21:19 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_list	*following;
	t_list	*a;
	int		nb;

	i = 1;
	if (argc <= 1)
		return (0);
	while (i < argc)
	{
		nb = atoi(argv[i]);
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
	if (argc > 0)
		ft_print_list(a);
	ft_lstclear(a);
	return (0);
}
