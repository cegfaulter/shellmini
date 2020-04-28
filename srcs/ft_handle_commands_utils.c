/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_commands_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:34:56 by settaqi           #+#    #+#             */
/*   Updated: 2020/02/03 02:24:42 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_retoldvalue(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == -1)
			line[i] = ' ';
		if (line[i] == -2)
			line[i] = ';';
		if (line[i] == -3)
			line[i] = '>';
		if (line[i] == -4)
			line[i] = '<';
		if (line[i] == -5)
			line[i] = '|';
		i++;
	}
}

char	*ft_join_char_str(char *str, char ch)
{
	char	*newstring;
	int		i;

	if (str == 0)
		return (0);
	if (!(newstring = (char*)malloc(sizeof(str) * ft_strlen(str) + 2)))
		return (0);
	i = 0;
	while (*str)
		newstring[i++] = *str++;
	newstring[i++] = ch;
	newstring[i] = 0;
	return (newstring);
}

char	*ft_remove_dq(char *str)
{
	char	*newstring;

	newstring = NULL;
	while (*str)
	{
		if (*str != '"')
		{
			if (*str == '\\' && *(str + 1) == '"')
				str++;
			if (newstring == NULL)
				newstring = ft_join_char_str("", *str);
			else
				newstring = ft_join_char_str(newstring, *str);
		}
		str++;
	}
	return (newstring);
}

char	*ft_remove_sq(char *str)
{
	char	*newstring;

	newstring = NULL;
	while (*str)
	{
		if (*str != '\'')
		{
			if (*str == '\\' && *(str + 1) == '\'')
				str++;
			if (newstring == NULL)
				newstring = ft_join_char_str("", *str);
			else
				newstring = ft_join_char_str(newstring, *str);
		}
		str++;
	}
	return (newstring);
}

void	ft_checkbuiltins(char *command, int *builtins)
{
	if (command == NULL)
		return ;
	if (ft_strncmp("echo", command, 4) == 0)
		*builtins = 1;
	else if (ft_strncmp("pwd", command, 3) == 0)
		*builtins = 2;
	else if (ft_strncmp("cd", command, 2) == 0)
		*builtins = 3;
	else if (ft_strncmp("export", command, 6) == 0)
		*builtins = 4;
	else if (ft_strncmp("unset", command, 5) == 0)
		*builtins = 5;
	else if (ft_strncmp("env", command, 3) == 0)
		*builtins = 6;
	else if (ft_strncmp("exit", command, 4) == 0)
		*builtins = 7;
	else
		*builtins = -1;
}

char	*ft_getabsolute_path(char *command, int *builtins)
{
	int				i;
	DIR				*pdir;
	struct dirent	*pdirent;

	i = 0;
	ft_checkbuiltins(command, builtins);
	if (*builtins >= 1)
		return (command);
	while (g_data.path_env[i])
	{
		pdir = opendir(g_data.path_env[i]);
		if (pdir != NULL)
		{
			while ((pdirent = readdir(pdir)) != NULL)
			{
				if (ft_strncmp(pdirent->d_name, command,
					ft_strlen(pdirent->d_name)) == 0)
				{
					*builtins = 0;
					return (ft_strjoin(ft_join_char_str(
						g_data.path_env[i], '/'), command));
				}
			}
		}
		closedir(pdir);
		i++;
	}
	return (command);
}

void	ft_handle_command_args(char **command, int *builtins)
{
	int		i;

	i = 0;
	while (command[i])
	{
		ft_retoldvalue(command[i]);
		if (command[i][0] == '"')
			command[i] = ft_remove_dq(command[i] + 1);
		else if (command[i][0] == '\'')
			command[i] = ft_remove_sq(command[i] + 1);
		else if (command[i][0] == '$')
			command[i] = ft_get_env(command[i] + 1);
		i++;
	}
	command[0] = ft_getabsolute_path(command[0], builtins);
}
