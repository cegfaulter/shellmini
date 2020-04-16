/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 03:19:20 by settaqi           #+#    #+#             */
/*   Updated: 2020/02/12 12:29:47 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/*
void		ft_writeintofile(int fd, char *filename, int mode)
{
	char	*line;
	int		fdfile;
	int		rt;

	fdfile = 0;
	if (mode == 2)
		fdfile = open(filename, O_WRONLY | O_CREAT | O_APPEND, 00700);
	else if (mode == 1)
		fdfile = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 00700);
	if (fdfile > 0)
	{
		rt = 1;
		while (rt > 0)
		{
			rt = get_next_line(fd, &line);
			ft_putstr_fd(line, fdfile);
			if (rt > 0)
				ft_putstr_fd("\n", fdfile);
		}
		close(fdfile);
	}
}

void		ft_dup2_input(t_command *item, int fdd)
{
	int		fd;

	fd = open(item->inputfilename, O_RDONLY);
	if (fd > 0)
		dup2(fd, 0);
	else
	{
		perror("error: ");
		item->errodetected = 1;
	}
}

void		ft_print_multipiperesult(void)
{
	t_list	*tmp_args;
	pid_t	pid;
	int		pipefd[2];
	int		fdd;

	tmp_args = g_data.list_args;
	while (tmp_args)
	{
		pipe(pipefd);
		pid = fork();
		if (pid == 0)
		{
			((t_command*)tmp_args->content)->errodetected = 0;
			if (((t_command*)tmp_args->content)->inputfile == 1)
				ft_dup2_input((t_command*)tmp_args->content, fdd);
			else
				dup2(fdd, 0);
			if (((t_command*)tmp_args->content)->errodetected != 1)
			{
				if (tmp_args->next != NULL)
				{
					dup2(pipefd[1], 1);
					dup2(pipefd[1], 2);
				}
				else
				{
					if (((t_command*)tmp_args->content)->saveit == 1)
					{
						dup2(pipefd[1], 1);
						dup2(pipefd[1], 2);
					}
				}
				if (((t_command*)tmp_args->content)->builtins >= 1)
					ft_runrightcmd(((t_command*)tmp_args->content), 0);
				else if (((t_command*)tmp_args->content)->builtins == 0)
					execve(((t_command*)tmp_args->content)->command[0],
						((t_command*)tmp_args->content)->command, g_data.envp);
				else
					printf("%s: command not found: %s\n", "minishell",
						((t_command*)tmp_args->content)->command[0]);
			}
			exit(0);
		}
		wait(NULL);
		close(pipefd[1]);
		if (((t_command*)tmp_args->content)->errodetected != 1)
		{
			fdd = dup(pipefd[0]);
			if (((t_command*)tmp_args->content)->saveit == 1)
			{
				ft_writeintofile(dup(pipefd[0]),
					((t_command*)tmp_args->content)->filename
					, ((t_command*)tmp_args->content)->mode);
				if (tmp_args->next != NULL)
					fdd = open(((t_command*)
						tmp_args->content)->filename, O_RDONLY);
			}
			if (((t_command*)tmp_args->content)->builtins >= 1)
				ft_runrightcmd(((t_command*)tmp_args->content), 1);
		}
		tmp_args = tmp_args->next;
	}
}*/


// int		main(void)
// {
// 	char	*data = "/bin/ls ls .";
// 	char	**data_splitted = ft_split(data, ' ');
// 	t_command	*item;
// 	// int		fd = open("test.txt", O_CREAT | O_WRONLY, 00700);

// 	item = (t_command*)malloc(sizeof(t_command) * 1);
// 	item->command = data_splitted;
// 	item->saveit = 1;
// 	item->filename = "hello.txt";
// 	item->mode = 1;
// 	ft_lstadd_back(&(g_data.list_args), ft_lstnew(item));
// 	data = "/usr/bin/grep grep .c";
// 	data_splitted = ft_split(data, ' ');
// 	item = (t_command*)malloc(sizeof(t_command) * 1);
// 	item->command = data_splitted;
// 	item->saveit = 1;
// 	item->filename = "test.txt";
// 	item->mode = 1;
// 	ft_lstadd_back(&(g_data.list_args), ft_lstnew(item));
// 	ft_print_multipiperesult();
// 	return (0);
// }

