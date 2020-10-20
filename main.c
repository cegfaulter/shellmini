/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 23:01:58 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/20 12:38:52 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		print_shell_line(void)
{
	int		i;

	i = 0;
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

void		ft_set_env_path(void)
{
	g_data.path_env = ft_split(get(g_map_env, "PATH"), ':');
}

int			main(int argc, char **argv, char **envp)
{
	char	*line;

	g_map_env = put_vars(envp);
	ft_init_data(argc, argv, envp);
	ft_set_env_path();
	while (1)
	{
		print_shell_line();
		g_data.gnl_return = get_next_line(0, &line);
		g_data.line = line;
		ft_commands_line();
		free(line);
		free_globals();
		line = 0;
	}
	return (0);
}


