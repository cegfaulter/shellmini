/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 03:24:05 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/23 19:29:56 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print_key_name(char *arg)
{
	while (*arg)
	{
		ft_putchar_fd(*arg, 2);
		arg++;
	}
	ft_putstr_fd("': not a valid identifier\n", 2);
}

int		ft_appendenv(char *arg)
{
	int		i;

	i = 0;
	while (*arg)
	{
		if (*(arg) == '+' && *(arg + 1) == '=')
			return (1);
		arg++;
	}
	return (0);
}

void	ft_print_export(t_command *item, t_cmap *map)
{
	char		**arr;

	arr = from_map_to_arr(map, 2);
	print_env(arr);
	free_split(&arr);
}

void	ft_export(t_command *item, int c)
{
	char	**data;
	char	**args;
	char	**env;
	
	args = item->command + 1;
	if (ft_split_length(item->command) <= 1)
		ft_print_export(item, g_map_env);
	while (*args)
	{
		if (!(data = split_export(*args, "&;|*?'\"‘[]()$<>{}#/!~/\\")))
		{
			ft_putstr_fd("Minishell: export: '", 2);
			ft_print_key_name(*args);
		}
		else
		{
			if (ft_appendenv(*args))
				setv(g_map_env, data[0], ft_strjoin(get(g_map_env, data[0]), data[1]));
			else
				setv(g_map_env, data[0], ft_cstrdup(data[1]));
			free(data[0]);
			free(data[1]);
			free(data);
		}
		args++;
	}
}
