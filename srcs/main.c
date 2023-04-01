/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:52:03 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/01 23:14:21 by bfaure           ###   ########lyon.fr   */
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

int	split_args(t_data *data)
{
	size_t	i;
	size_t	j;

	ft_printf("============================V1=================================\n");
	i = 0;
	data->tab_list = ft_split(data->arg, ' ');
	if (!data->tab_list)
		return (free_tab(data->tab_list), -1);
	while (data->tab_list[i])
	{
		ft_printf("data.tab_list[%i] = %s\n", i, data->tab_list[i]);
		i++;
	}
	ft_printf("============================V2=================================\n");
	i = 0;
	while (data->tab_list[i])
	{
		j = 0;
		while (data->tab_list[i][j])
		{
			if (data->tab_list[i][j] >= -9 && data->tab_list[i][j] <= 9)
				return (free_all(data), -1);
			ft_printf("data.tab_list[%i][%i] = %c\n", i, j, data->tab_list[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}

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
