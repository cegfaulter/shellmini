/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 23:01:58 by settaqi           #+#    #+#             */
/*   Updated: 2020/02/12 17:46:50 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		print_shell_line(void)
{
	char	currentdirectory[65535];
	int		i;

	i = 0;
	getcwd(currentdirectory, 65535);
	g_data.currentdirectory = ft_strdup(currentdirectory);
	ft_update_env_pwd();
	if (g_data.home_directory != NULL)
	{
		if (ft_strncmp(g_data.home_directory, currentdirectory,
				ft_strlen(g_data.home_directory)) == 0)
			print("~%s $ ", currentdirectory +
				ft_strlen(g_data.home_directory));
		else
			print("%s $ ", currentdirectory);
	}
}

void		ft_set_env_path(void)
{
	g_data.path_env = ft_split(ft_get_env("PATH"), ':');
}

int			main(int argc, char **argv, char **envp)
{
	char	*line;

	g_v_args = envp;
	ft_init_data(argc, argv, envp);
	ft_set_envp();
	ft_set_env_path();
    g_map_env = put_vars(envp);
	while (1)
	{
		print_shell_line();
		g_data.gnl_return = get_next_line(0, &line);
		g_data.line = line;
		ft_commands_line();
		free(line);
		line = 0;
	}
	return (0);
}
