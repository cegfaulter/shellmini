/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:22:17 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/20 10:19:30 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset(t_command *item, int c)
{
	char	**args;
	char	**tmp;

	args = item->command;
	while (*args)
	{
		popv(g_map_env, *args);
		args++;
	}
	g_map_env = put_vars(update_print_env(0));
}
