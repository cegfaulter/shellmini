/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:17:58 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/26 13:47:38 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_changedirectory(t_command *item, int c)
{
	DIR		*pdir;
	char	*to_directory;
	char	*current_directory;

	to_directory = item->command[1] == 0 ? get(g_map_env, "HOME") : item->command[1];
	pdir = opendir(to_directory);
	if (pdir != NULL)
	{
		setv(g_map_env, "OLDPWD", ft_strdup(get(g_map_env, "PWD")));
		chdir(to_directory);
		current_directory = ft_getcurrentdirectory();
		if (current_directory == NULL)
			setv(g_map_env, "PWD", ft_strjoin(get(g_map_env, "PWD"), "/."));
		else
			setv(g_map_env, "PWD", current_directory);
	}
	else
	{
		setv(g_map_env, "?", ft_itoa(1));
		if (c == 0)
			ft_print_error();
	}
	if (pdir)
		closedir(pdir);
}
