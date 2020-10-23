/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 03:24:05 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/21 11:46:51 by settaqi          ###   ########.fr       */
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

void	ft_export(t_command *item, int c)
{
	char	**data;
	char	**args;
	char	**env;
	
	args = item->command + 1;
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
