/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runbuiltins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:12:57 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/21 12:06:17 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_runrightcmd(t_command *item, int c)
{
	int		i;
	char	**env;

	if (item->builtins == 1)
		ft_echo_builtins(item, c);
	else if (item->builtins == 2)
		ft_pwd(c);
	else if (item->builtins == 3)
		ft_changedirectory(item, c);
	else if (item->builtins == 4)
		ft_export(item, c);
	else if (item->builtins == 5)
		ft_unset(item, c);
	else if (item->builtins == 6)
	{
		env = update_print_env(c);
		free_split(&env);
	}
	else if (item->builtins == 7)
		ft_exit(c);
}
