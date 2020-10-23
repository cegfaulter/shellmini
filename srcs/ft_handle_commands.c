/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:16:32 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/21 13:49:58 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_ctrl_d(void)
{
	ft_putstr_fd("exit\n", 2);
	exit(0);
}

void		ft_free_split(char **data)
{
	int		i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		data[i] = NULL;
		i++;
	}
	free(data);
	data = 0;
}

int			ft_split_length(char **data_splitted)
{
	int		i;

	i = 0;
	while (data_splitted[i])
		i++;
	return (i);
}

char		**ft_list_to_arr(t_clist *list, char *cmd)
{
	char	**commands;
	int		i;
	t_clist *tmp;

	i = 1;
	commands = (char**)malloc(sizeof(char*) * (ft_lstsize((t_list*)list) + 2));
	commands[0] = cmd;
	tmp = list;
	while (tmp)
	{
		commands[i++] = (char*)tmp->data;
		tmp = tmp->next;
	}
	commands[i] = 0;
	return (commands);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	return (*s1 - *s2);
}

void			ft_putfiles(t_rec *list, t_command *cmd)
{
	t_clist		*tmp_file;
	t_clist		*tmp_operator;
	t_files		*file;

	if (ft_lstsize((t_list*)list->files) != ft_lstsize((t_list*)list->oper))
		g_data.error_detected = 2;
	else
	{
		cmd->files = NULL;
		tmp_file = (t_clist*)list->files;
		tmp_operator = (t_clist*)list->oper;
		while (tmp_file && tmp_operator)
		{
			file = (t_files*)malloc(sizeof(t_files) * 1);
			file->filename = (char*)tmp_file->data;
			if (ft_strcmp((char*)tmp_operator->data, ">") == 0)
			{
				file->mode = 1;
				file->fd = open(file->filename, O_WRONLY | O_CREAT | O_TRUNC,
								00700);
			}
			else if (ft_strcmp((char*)tmp_operator->data, ">>") == 0)
			{
				file->mode = 2;
				file->fd = open(file->filename, O_WRONLY | O_CREAT | O_APPEND,
								00700);
			}
			else
			{
				file->mode = 0;
				file->fd = open(file->filename, O_RDONLY);
			}
			if (file->fd == -1)
				g_data.error_detected = 3;
			ft_lstadd_back(&(cmd->files), ft_lstnew(file));
			tmp_file = tmp_file->next;
			tmp_operator = tmp_operator->next;
		}
	}
}

void			ft_createargs(char *cmd, t_rec *cmd_param, int *builtin)
{
	t_command	*entirecommand;

	entirecommand = (t_command*)malloc(sizeof(t_command) * 1);
	entirecommand->command = ft_list_to_arr(cmd_param->text, cmd);
	ft_putfiles(cmd_param, entirecommand);
	entirecommand->builtins = *builtin;
	ft_lstadd_back(&(g_data.list_args), ft_lstnew(entirecommand));
}

t_clist     *all_commands(char *s, t_cmap *global_env)
{
    t_clist     *all;
    char        **cmds;
    int         iter;
	t_clist		*lst;
	t_ccommand	*hi;
	int			builtin;
	t_clist		*tmplst;

    all = NULL;
    cmds = csplit(s, ';');
    iter = 0;
	builtin = 0;
    while (cmds[iter])
    {
        append(&all, get_command_line(cmds[iter], g_map_env));
		tmplst = all;
		while (all)
		{
			g_data.error_detected = 0;
			lst = (t_clist *)all->data;
			g_data.list_args = NULL;
			while (lst)
			{
				hi = (t_ccommand *)lst->data;
				ft_createargs(
					ft_getabsolute_path((char *)hi->cmd, &builtin),
					(t_rec *)hi->data,
					&builtin);
				lst = lst->next;
			}
			if (!g_data.error_detected)
				ft_print_multipiperesult();
			else
				ft_print_error();
			ft_data_list(&g_data.list_args);
			all = all->next;
		}
		free_all_commands(&tmplst);
        iter++;
    }
    free_split(&cmds);
    return (all);
}

void		ft_handlecommands(char *cmd)
{
	t_clist		*all;

	all = NULL;
	all = all_commands(cmd, g_map_env);
}

void		ft_commands_line(void)
{
	if (*(g_data.line) == 0 && g_data.gnl_return == 0)
		ft_ctrl_d();

	ft_handlecommands(g_data.line);
}
