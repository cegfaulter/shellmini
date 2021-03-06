/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_commands_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:34:56 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/23 13:35:01 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_getcurrentdirectory(void)
{
	char	currentdirectory[65535];
	char	*directory;

	directory = getcwd(currentdirectory, 65535);
	return (directory ? ft_strdup(directory) : NULL);
}

void	ft_checkbuiltins(char *command, int *builtins)
{
	if (command == NULL)
		return ;
	if (ft_strcmp("echo", command) == 0)
		*builtins = 1;
	else if (ft_strcmp("pwd", command) == 0)
		*builtins = 2;
	else if (ft_strcmp("cd", command) == 0)
		*builtins = 3;
	else if (ft_strcmp("export", command) == 0)
		*builtins = 4;
	else if (ft_strcmp("unset", command) == 0)
		*builtins = 5;
	else if (ft_strcmp("env", command) == 0)
		*builtins = 6;
	else if (ft_strcmp("exit", command) == 0)
		*builtins = 7;
	else
		*builtins = -1;
}

int		ft_max(char *str1, char *str2)
{
	int		str1len;
	int		str2len;

	str1len = ft_strlen(str1);
	str2len = ft_strlen(str2);
	return (str1len > str2len ? str1len : str2len);
}

char	*set_theasbolute(char *path_env, char *command, int *builtins)
{
	char	*add_;
	char	*absolute_path;

	*builtins = 0;
	add_ = ft_strjoin(path_env, "/");
	absolute_path = ft_strjoin(add_, command);
	free(add_);
	add_ = NULL;
	return (absolute_path);
}

char	*ft_getabsolute_path(char *command, int *builtins)
{
	int				i;
	DIR				*pdir;
	struct dirent	*pdirent;

	i = 0;
	if (command == NULL)
		return (ft_cstrdup(""));
	ft_checkbuiltins(command, builtins);
	if (*builtins >= 1)
		return (command);
	if (!g_data.path_env)
		return (command);
	while (g_data.path_env[i])
	{
		pdir = opendir(g_data.path_env[i]);
		if (pdir != NULL)
		{
			while ((pdirent = readdir(pdir)) != NULL)
			{
				if (ft_strcmp(pdirent->d_name, command) == 0)
				{
					closedir(pdir);
					return (set_theasbolute(g_data.path_env[i],
							command, builtins));
				}
			}
			closedir(pdir);
		}
		i++;
	}
	return (command);
}
