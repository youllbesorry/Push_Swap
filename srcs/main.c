/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:52:03 by bfaure            #+#    #+#             */
/*   Updated: 2023/03/31 14:20:33 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	join_arg(int argc, char **argv, t_data *data)
{
	int		i;

	i = 1;
	if (argc <= 1)
		return (0);
	while (i < argc)
	{
		if (i == 1)
		{
			data->arg = ft_strdup(argv[i]);
			if (!data->arg)
				return (-1);
		}
		else
		{
			data->arg = ft_strfjoin(data->arg, " ");
			if (!data->arg)
				return (free(data->arg), -1);
			data->arg = ft_strfjoin(data->arg, argv[i]);
			if (!data->arg)
				return (free(data->arg), -1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if(join_arg == -1)
	return (0);
}
