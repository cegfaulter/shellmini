/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runbuiltins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:12:57 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/20 12:21:07 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_runrightcmd(t_command *item, int c)
{
	int		i;

	if (item->builtins == 1)
		ft_echo_builtins(item, c);
	else if (item->builtins == 2)
		ft_pwd(c);
	else if (item->builtins == 3)
		ft_changedirectory(item, c);
	else if (item->builtins == 4)
		ft_export(c);
	else if (item->builtins == 5)
		ft_unset(item, c);
	else if (item->builtins == 6)
		update_print_env(c);
	else if (item->builtins == 7)
		ft_exit(c);
}
