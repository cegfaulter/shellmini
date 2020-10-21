/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:22:17 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/21 12:11:41 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset(t_command *item, int c)
{
	char	**args;
	char	**tmp;
	char	**env;

	args = item->command + 1;
	while (*args)
	{
		popv(g_map_env, *args);
		args++;
	}
	env = update_print_env(0);
	clear_map(&g_map_env, free_vars);
	g_map_env = put_vars(env);
	free_split(&env);
}
