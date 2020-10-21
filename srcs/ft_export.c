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

void	ft_export(t_command *item, int c)
{
	char	**data;
	char	**args;
	
	args = item->command + 1;
	while (*args)
	{
		if (!(data = split_export(*args, "&;|*?'\"‘[]()$<>{}#/!~+-/\\")))
		{
			ft_putstr_fd("Minishell: export: '", 2);
			ft_print_key_name(*args);
		}
		else
		{
			setv(g_map_env, data[0], ft_cstrdup(data[1]));
			free(data[0]);
			free(data[1]);
			free(data);
		}
		args++;
	}
}
