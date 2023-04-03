/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:13:10 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/03 19:32:09 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	join_arg(int argc, char **argv, t_data *data)
{
	int		i;

	i = 1;
	if (argc <= 1)
		return (0);
	ft_printf("============================V1=================================\n");
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
		ft_printf("argv[%i] = %s\n", i, argv[i]);
		i++;
	}
	return (0);
}

int	split_args(t_data *data)
{
	size_t	i;

	ft_printf("============================V2=================================\n");
	i = 0;
	data->tab_list = ft_split(data->arg, ' ');
	if (!data->tab_list)
		return (free_tab(data->tab_list), -1);
	while (data->tab_list[i])
	{
		ft_printf("data.tab_list[%i] = %s\n", i, data->tab_list[i]);
		i++;
	}
	return (0);
}

int	check_val_args(t_data *data)
{
	size_t	i;
	size_t	j;

	ft_printf("============================V3=================================\n");
	i = 0;
	while (data->tab_list[i])
	{
		j = 0;
		while (data->tab_list[i][j])
		{
			if (!(data->tab_list[i][j] >= 48 && data->tab_list[i][j] <= 59))
			{
				if (((data->tab_list[i][j] == 45 || data->tab_list[i][j] == 43)
					&& (!(data->tab_list[i][j + 1] >= 48
						&& data->tab_list[i][j + 1] <= 59))))
					return (free_all(data), -1);
			}
			if ((data->tab_list[i][j] != 43 && data->tab_list[i][j] != 45)
					&& (!(data->tab_list[i][j] >= 48
						&& data->tab_list[i][j] <= 59)))
				return (free_all(data), -2);
			j++;
		}
		ft_printf("data.tab_list[%i] = %s\n", i, data->tab_list[i]);
		i++;
	}
	return (0);
}

int	check_weird_args(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	sign;

	ft_printf("============================V4=================================\n");
	i = 0;
	sign = 0;
	while (data->tab_list[i])
	{
		j = 0;
		while (data->tab_list[i][j])
		{
			if ((data->tab_list[i][j] >= 48 && data->tab_list[i][j] <= 59
				&& (data->tab_list[i][j + 1] == 45
					|| data->tab_list[i][j + 1] == 43)))
				return (free_all(data), -1);
			if (data->tab_list[i][j] == 45 || data->tab_list[i][j] == 43)
				sign++;
			if (sign > 1)
				return (free_all(data), -2);
			j++;
		}
		ft_printf("data->tab_list[%i] = %s\n", i, data->tab_list[i]);
		i++;
		sign = 0;
	}
	return (0);
}

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

