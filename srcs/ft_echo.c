/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 03:21:14 by settaqi           #+#    #+#             */
/*   Updated: 2020/02/12 17:49:49 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo_builtins(t_command *item, int c)
{
	char	**command_line;
	int		i;
	int		newline;

	if (c == 0)
	{
		i = 1;
		newline = 1;
		command_line = item->command;
		while (ft_strncmp("-n", command_line[i],
			ft_strlen(command_line[i])) == 0)
		{
			newline = 0;
			i++;
		}
		while (command_line[i])
		{
			ft_putstr_fd(command_line[i], 1);
			if (command_line[i + 1] != 0)
				ft_putchar_fd(' ', 1);
			i++;
		}
		if (newline)
			ft_putchar_fd(' ', 1);
	}
}

/*
int		main(int argc, char **argv, char **envp)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		ft_echo(argv[i], i, argc);
		i++;
	}
	if (ft_strncmp(argv[1], "-n", ft_strlen(argv[1])))
		printf("\n");
	return (0);
}
*/
/*
void		ft_echo(void)
{
	t_list		*tmp;
	int			displaynewline;

	tmp = g_args.list_args;
	displaynewline = 0;
	while (tmp && *((char*)tmp->content) != '>'
			&& *((char*)tmp->content) != '|')
	{
		if (ft_strncmp("-n", ((char*)tmp->content),
			ft_strlen(((char*)tmp->content))))
		{
			ft_printf("%s", ((char*)tmp->content));
			if (tmp->next && *((char*)tmp->next->content) != '>'
				&& *((char*)tmp->next->content) != '|')
				ft_putchar(' ');
		}
		else
			displaynewline = 1;
		tmp = tmp->next;
	}
	if (displaynewline == 0)
		ft_putchar('\n');
}

int			ft_setup_filedescriptor_echo(char *filename, int mode)
{
	int		fd;

	if (mode == 0)
	{
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 00700);
		if (fd < 0)
			perror("echo");
	}
	if (mode == 1)
	{
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 00700);
		if (fd < 0)
			perror("echo");
	}
	return (fd);
}

void		ft_setup_a_new_proccess_echo(char *filename, int mode)
{
	pid_t	pid;
	int		fd;

	fd = ft_setup_filedescriptor_echo(filename, mode);
	if (fd < 0)
		return ;
	pid = fork();
	if (pid < 0)
		perror("echo");
	else if (pid == 0)
	{
		dup2(fd, STDOUT_FILENO);
		ft_echo();
		close(fd);
		exit(0);
	}
	close(fd);
}

void		ft_checkpipeandredirect(void)
{
	t_list		*tmp;
	int			md;

	tmp = g_args.list_args;
	md = 0;
	while (tmp)
	{
		if (ft_strncmp(">", ((char*)tmp->content),
			ft_strlen(((char*)tmp->content))) == 0)
		{
			if (tmp->next != NULL)
				ft_setup_a_new_proccess_echo(((char*)tmp->next->content), 0);
			else
				ft_putstr("Minishell: You should enter a filename\n");
			md = 1;
		}
		else if (ft_strncmp(">>", ((char*)tmp->content),
			ft_strlen(((char*)tmp->content))) == 0)
		{
			if (tmp->next != NULL)
				ft_setup_a_new_proccess_echo(((char*)tmp->next->content), 1);
			else
				ft_putstr("Minishell: You should enter a filename\n");
			md = 1;
		}
		tmp = tmp->next;
	}
	if (md == 0)
		ft_echo();
}
*/
