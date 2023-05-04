/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:13:10 by bfaure            #+#    #+#             */
/*   Updated: 2023/05/04 10:08:16 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	join_arg(int argc, char **argv, t_data *data)
{
	int		i;

	i = 1;
	if (argc <= 1)
		return (-1);
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
	data->tab_list = ft_split(data->arg, ' ');
	if (!data->tab_list)
		return (free_all(data), ft_putstr_fd("Error\n", 2), -1);
	if (!data->tab_list[0])
		return (free_all(data), -1);
	return (0);
}

int	check_val_args(t_data *data)
{
	size_t	i;
	size_t	j;

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
				return (free_all(data), -1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_weird_args(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	sign;

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
				return (free_all(data), -1);
			j++;
		}
		i++;
		sign = 0;
	}
	return (0);
}

int	check_multiple_same_digits(t_list *lst)
{
	t_list	*head;
	t_list	*tmp_lst;
	int		tmp;

	tmp = lst->content;
	head = lst;
	while (lst)
	{
		tmp = lst->content;
		lst = lst->next;
		tmp_lst = lst;
		while (tmp_lst)
		{
			if (tmp == tmp_lst->content)
				return (ft_lstclear(head), -1);
			tmp_lst = tmp_lst->next;
		}
	}
	lst = head;
	return (0);
}
