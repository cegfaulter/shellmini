/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initdata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:25:05 by settaqi           #+#    #+#             */
/*   Updated: 2020/01/27 17:29:22 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_set_homedirectory(void)
{
	int		i;
	char	*home_directory;
	char	**splitted_data;

	home_directory = NULL;
	i = 0;
	while (g_data.envp[i])
	{
		splitted_data = ft_split(g_data.envp[i], '=');
		if (ft_strlen(splitted_data[0]) == 4)
			if (ft_strncmp(splitted_data[0], "HOME", 4) == 0)
				home_directory = ft_strdup(splitted_data[1]);
		ft_free_split(&splitted_data);
		i++;
	}
	g_data.home_directory = home_directory;
}

void		ft_init_data(int argc, char **argv, char **envp)
{
	g_data.argc = argc;
	g_data.argv = argv;
	g_data.envp = envp;
	ft_set_homedirectory();
}
