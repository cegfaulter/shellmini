/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 23:01:58 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/26 12:54:10 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		print_shell_line(void)
{
	int		i;

	i = 0;
	if (g_data.print_shell_line == 1) {
		g_data.currentdirectory = ft_getcurrentdirectory();
		if (g_data.home_directory != NULL)
		{
			if (ft_strncmp(g_data.home_directory, g_data.currentdirectory,
					ft_strlen(g_data.home_directory)) == 0)
				print("~%s $ ", g_data.currentdirectory +
					ft_strlen(g_data.home_directory));
			else
				print("%s $ ", g_data.currentdirectory);
		}
	}
}

void		ft_set_env_path(void)
{
	if (g_data.path_env)
		free_split(&g_data.path_env);
	g_data.path_env = ft_split(get(g_map_env, "PATH"), ':');
}

int			main(int argc, char **argv, char **envp)
{
	char	*line;
	int		i;
	int		status;

	g_map_env = put_vars(envp);
	i = 0;
	ft_init_data(argc, argv, envp);
	ft_signal();
	g_data.print_shell_line = 0;
	while (1)
	{
		g_data.error_detected = 0;
		ft_set_env_path();
		print_shell_line();
		g_data.gnl_return = get_next_line(0, &line);
		if (g_data.gnl_return == 0)
		{
			ft_putstr_fd("exit\n", 2);
			exit(ft_atoi(get(g_map_env, "?")));
		}
		if (g_data.error_detected == 9)
			continue ;
		g_data.line = line;
		ft_commands_line();
		free(line);
		line = NULL;
		free_globals();
	}
	clear_map(&g_map_env, free_vars);
	return (ft_atoi(get(g_map_env, "?")));
}
