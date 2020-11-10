/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 03:20:49 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/20 10:48:40 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_current_directory(void)
{
	char	*directory;
	char	currentdirectory[65535];

	getcwd(currentdirectory, 65535);
	directory = get(g_map_env, "PWD");
	if (directory == 0)
		directory = currentdirectory;
	return (ft_strdup(directory));
}

void	ft_pwd(int c)
{
	char	*directory;

	if (c == 1)
	{
		directory = get_current_directory();
		ft_putstr_fd(directory, 1);
		ft_putstr_fd("\n", 1);
		free(directory);
	}
}
