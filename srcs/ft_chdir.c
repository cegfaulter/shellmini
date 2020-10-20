/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:17:58 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/20 11:43:35 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_changedirectory(t_command *item, int c)
{
	DIR		*pdir;
	char	*to_directory;

	to_directory = item->command[1] == 0 ? "" : item->command[1];
	pdir = opendir(to_directory);
	if (pdir != NULL)
	{
		setv(g_map_env, "OLDPWD", ft_strdup(get(g_map_env, "PWD")));
		chdir(to_directory);
		setv(g_map_env, "PWD", ft_getcurrentdirectory());
	}
	else
	{
		if (c == 0)
		{
			ft_putstr_fd("Minishell: ", 2);
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd("\n", 2);
		}
	}
}
