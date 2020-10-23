/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:03:37 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/23 16:45:20 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_globals(void)
{
	free(g_data.currentdirectory);
}

void	free_files(t_files *file)
{
	close(file->fd);
	free(file);
}

void	free_t_commands(t_command *command)
{
	if (command->builtins == 0)
		free(command->command[0]);
	ft_lstclear(&command->files, (void*)free_files);
	free(command->command);
	command->command = NULL;
	free(command);
	command = NULL;
}

void	ft_data_list(t_list **list)
{
	ft_lstclear(list, (void*)free_t_commands);
}
