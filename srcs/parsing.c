/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:13:10 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/13 16:31:20 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	join_arg(int argc, char **argv, t_data *data)
{
	int		i;

	i = 1;
	if (argc <= 1)
		return (0);
	ft_printf(RED"============================V1=================================\n"END);
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

	ft_printf(RED"============================V2=================================\n"END);
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

	ft_printf(RED"============================V3=================================\n"END);
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

	ft_printf(RED"============================V4=================================\n"END);
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

int	check_multiple_same_digits(t_list *lst)
{
	t_list	*tmp_lst;
	int		tmp;

	tmp = lst->content;
	ft_printf(RED"============================V5=================================\n"END);
	while (lst)
	{
		tmp = lst->content;
		lst = lst->next;
		tmp_lst = lst;
		ft_printf("content tmp %i\n", tmp);
		while (tmp_lst)
		{
			ft_printf("content tmp_lst->content %d\n", tmp_lst->content);
			if (tmp == tmp_lst->content)
				return (ft_lstclear(lst), -1);
			tmp_lst = tmp_lst->next;
		}
	}
	return (0);
}
