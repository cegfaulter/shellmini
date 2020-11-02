/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 03:19:20 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/26 14:07:23 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			ft_file_last(t_list *list, int mode_1, int mode_2)
{
	int		position;
	int		i;
	t_list	*tmp;

	i = 0;
	position = -1;
	tmp = list;
	while(tmp)
	{
		if (((t_files*)tmp->content)->mode == mode_1 || ((t_files*)tmp->content)->mode == mode_2)
			position = i;
		tmp = tmp->next;
		i++;
	}
	return (position);
}

void		ft_read_or_save(t_list *list, int fd)
{
	t_list	*tmp;
	int		inp;
	int		i;
	int		std_in;
	int		std_out;

	tmp = list;
	inp = 0;
	i = 0;
	std_in = ft_file_last(list, 0, 0);
	std_out = ft_file_last(list, 1, 2);
	while (tmp)
	{
		if (std_in == i)
		{
			dup2(((t_files*)tmp->content)->fd, STDIN_FILENO); // error here can't not dup stdin with file descriptor
			inp = 1;
		}
		else if (std_out == i)
		{
			dup2(((t_files*)tmp->content)->fd, STDOUT_FILENO);
		}
		else
		{
			close(((t_files*)tmp->content)->fd);
		}
		i++;
		tmp = tmp->next;
	}
	if (inp == 0)
	{
		dup2(fd, STDIN_FILENO);
	}
		
}

int		execute_cmd(t_command *cmd)
{
	int		status;

	if (cmd->builtins >= 1)
		ft_runrightcmd(cmd, 1);
	else
	{
		status = execve(cmd->command[0], cmd->command, update_print_env(0));
		if (status == -1)
		{
			ft_putstr_fd("Minishell: ", 2);
			ft_putstr_fd(cmd->command[0], 2);
			ft_putstr_fd(": command not found\n", 2);
		}
	}
	return (status == -1 ? 32385 : status);
}

void		close_fd(fd, pipe_fd_1, pipe_fd_2)	
{
	close(fd);
	close(pipe_fd_1);
	close(pipe_fd_2);
}

void		new_proccess(t_list *tmp_args, int pipefd[], int fd)
{
	int		status;

	if (tmp_args->next != NULL)
		dup2(pipefd[1], 1);
	ft_read_or_save(((t_command*)tmp_args->content)->files, fd);
	status = execute_cmd(((t_command*)tmp_args->content));
	close_fd(fd, pipefd[0], pipefd[1]);
	exit(status / 255);
}

void		ft_print_multipiperesult(void)
{
	t_list	*tmp_args;
	pid_t	pid;
	int		pipefd[2];
	int		fd;
	int		status;

	tmp_args = g_data.list_args;
	fd = -1;
	while (tmp_args)
	{
		pipe(pipefd);
		pid = fork();
		if (pid == 0)
			new_proccess(tmp_args, pipefd, fd);
		else if (pid <= -1)
			ft_print_error();
		waitpid(pid, &status, WUNTRACED);
		if (((t_command*)tmp_args->content)->builtins >= 1)
			ft_runrightcmd(((t_command*)tmp_args->content), 0);
		else
			setv(g_map_env, "?", ft_itoa(status / 255));
		close(pipefd[1]);
		close(fd);
		fd = dup(pipefd[0]);
		close(pipefd[0]);
		tmp_args = tmp_args->next;
	}
	close(fd);
	close(pipefd[0]);
	close(pipefd[1]);
}
