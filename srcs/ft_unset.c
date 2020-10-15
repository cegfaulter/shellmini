/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:22:17 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/14 11:50:37 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset(t_command *item)
{
	char	**args;
	t_clist	**lst;

	args = item->command + 1;
	lst = g_map_env->lst;
	while (args)
	{
		popv(g_map_env, *args);
		args++;
	}
}
