/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:17:58 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/23 14:14:51 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_changedirectory(t_command *item, int c)
{
	DIR		*pdir;
	char	*to_directory;

	to_directory = item->command[1] == 0 ? get(g_map_env, "HOME") : item->command[1];
	pdir = opendir(to_directory);
	if (pdir != NULL)
	{
		setv(g_map_env, "OLDPWD", ft_getcurrentdirectory());
		chdir(to_directory);
		if (ft_strcmp(".", to_directory) == 0)
			setv(g_map_env, "PWD", ft_strjoin(get(g_map_env, "OLDPWD"), "/."));
		else
			setv(g_map_env, "PWD", ft_getcurrentdirectory());
	}
	else
	{
		if (c == 0)
			ft_print_error();
	}
	closedir(pdir);
}
