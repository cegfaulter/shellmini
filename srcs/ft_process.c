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

char    *ft_read_current_fd(int fd)
{
    char    *data = NULL;
    char    *line;
    int     i = 1;

    while (i > 0)
    {
        i = get_next_line(fd, &line);
        if (data == NULL)
            data = ft_strjoin("", line);
        else
            data = ft_strjoin(data, line);
        if (i > 0)
            data = ft_strjoin(data, "\n");
        free(line);
    }
    return (data);
}

void        ft_read_or_save(t_list *list)
{
    t_list  *tmp;

    tmp = list;
    while (tmp)
    {
        if (((t_files*)tmp->content)->mode == 0 && tmp->next == NULL)
            dup2(((t_files*)tmp->content)->fd, 0);
        else if ((((t_files*)tmp->content)->mode == 1 || ((t_files*)tmp->content)->mode == 2) && tmp->next == NULL)
            dup2(((t_files*)tmp->content)->fd, 1);
        else
            close(((t_files*)tmp->content)->fd);
        tmp = tmp->next;
    }
}

void		ft_print_multipiperesult(void)
{
	t_list	*tmp_args;
	pid_t	pid;
	int		pipefd[2];
    char    *data;
    int     fd;

	tmp_args = g_data.list_args;
    fd = 0;
	while (tmp_args)
	{
		pipe(pipefd);
		pid = fork();
		if (pid == 0)
		{
            dup2(fd, 0);
            if (tmp_args->next != NULL)
                dup2(pipefd[1], 1);
            ft_read_or_save(((t_command*)tmp_args->content)->files);
            if (((t_command*)tmp_args->content)->builtins >= 1)
                ft_runrightcmd(((t_command*)tmp_args->content), 1);
            else
            {
                if (execve(((t_command*)tmp_args->content)->command[0],
				((t_command*)tmp_args->content)->command, g_data.envp) == -1)
                {
                    ft_putstr_fd("Minishell: ", 2);
                    ft_putstr_fd(((t_command*)tmp_args->content)->command[0], 2);
                    ft_putstr_fd(": command not found\n", 2);
                }

            }
            close(fd);
            close(pipefd[1]);
            close(pipefd[0]);
			exit(0);
		}
        if (((t_command*)tmp_args->content)->builtins == 3)
            ft_runrightcmd(((t_command*)tmp_args->content), 0);
		wait(NULL);
		close(pipefd[1]);
        fd = dup(pipefd[0]);
        close(pipefd[0]);
		tmp_args = tmp_args->next;
	}
}


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

