/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:17:58 by settaqi           #+#    #+#             */
/*   Updated: 2020/02/03 15:34:17 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_set_env_oldpwd(void)
{
	int		rtenvupdate;

	rtenvupdate = ft_update_envp("OLDPWD", g_data.currentdirectory);
	if (rtenvupdate == 0)
		ft_add_envp("OLDPWD", g_data.currentdirectory);
}

void		ft_update_env_pwd(void)
{
	int		rtenvupdate;

	rtenvupdate = ft_update_envp("PWD", g_data.currentdirectory);
	if (rtenvupdate == 0)
		ft_add_envp("PWD", g_data.currentdirectory);
}

void		ft_changedirectory(t_command *item, int c)
{
	DIR		*pdir;
	char	*to_directory;

	to_directory = item->command[1] == 0 ? "" : item->command[1];
	ft_set_env_oldpwd();
	pdir = opendir(to_directory);
	if (pdir != NULL)
		chdir(to_directory);
	else
	{
        if (c != 0)
            printf("Minishell: %s\n", strerror(errno));
	}
}

/*
int			main(int argc, char **argv, char **envp)
{
	if (argc == 2)
		ft_changedirectory("hello", argv[1]);
	return (0);
}
*/
