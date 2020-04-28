/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:16:32 by settaqi           #+#    #+#             */
/*   Updated: 2020/02/12 18:20:20 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_ctrl_d(void)
{
	ft_putstr_fd("exit\n", 1);
	exit(0);
}

void		ft_free_split(char ***data)
{
	int		i;

	i = 0;
	while ((*data)[i])
		free((*data)[i++]);
	free(*data);
	*data = 0;
}

int			ft_split_length(char **data_splitted)
{
	int		i;

	i = 0;
	while (data_splitted[i])
		i++;
	return (i);
}

char        **ft_list_to_arr(t_clist *list, char *cmd)
{
    char    **commands;
    int     i;
    t_clist *tmp;

    i = 1;
    commands = (char**)malloc(sizeof(char*) * (ft_lstsize((t_list*)list) + 2));
    commands[0] = ft_strdup(cmd);
    tmp = list;
    while (tmp)
    {
        commands[i++] = ft_strdup((char*)tmp->data);
        tmp = tmp->next;
    }
    commands[i] = 0;
    return (commands);
}

int         ft_strcmp(char *s1, char *s2)
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

void        ft_putfiles(t_rec *list, t_command *cmd)
{
    t_clist     *tmp_file;
    t_clist     *tmp_operator;
    t_files     *file;

    if (ft_lstsize((t_list*)list->files) != ft_lstsize((t_list*)list->oper))
        g_data.error_detected = 1;
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
                file->fd = open(file->filename, O_WRONLY | O_CREAT | O_TRUNC, 00700);
            }
            else if(ft_strcmp((char*)tmp_operator->data, ">>") == 0)
            {
                file->mode = 2;
                file->fd = open(file->filename, O_WRONLY | O_CREAT | O_APPEND, 00700);
            }
            else
            {
                file->mode = 0;
                file->fd = open(file->filename, O_RDONLY);
            }
            ft_lstadd_back(&(cmd->files), ft_lstnew(file));
            tmp_file = tmp_file->next;
            tmp_operator = tmp_operator->next;
        }
    }
}

void        ft_createargs(char *cmd, t_rec *cmd_param, int *builtin)
{
    t_command   *entirecommand;

    entirecommand = (t_command*)malloc(sizeof(t_command) * 1);
    entirecommand->command = ft_list_to_arr(cmd_param->text, cmd);
    ft_putfiles(cmd_param, entirecommand);
    entirecommand->builtins = *builtin;
    ft_lstadd_back(&(g_data.list_args), ft_lstnew(entirecommand));
}

void		ft_handlecommands(char *cmd)
{
	char        **sp;
    int         iter;
    t_clist     *lst = NULL;
    t_clist     *all = NULL;
    t_ccommand  *hi;
    t_rec       *cmd_param;
    int         bultin;

	all = all_commands(cmd, g_v_args);
    bultin = 0;
	while (all)
	{
		lst = (t_clist *)all->data;
        g_data.list_args = NULL;
		while (lst)
		{
            hi = (t_ccommand *)lst->data;
            ft_createargs(
                ft_getabsolute_path((char *)hi->cmd, &bultin),
                (t_rec *)hi->data,
                &bultin
            );
			lst = lst->next;
		}
        ft_print_multipiperesult();
		all = all->next;
	}
	//free_all_commands(&lst);
}

void		ft_commands_line(void)
{
	char	**splite_cmds;
	int		lengthcmds;
	char	**data_splitted;
	int		i;

	if (*(g_data.line) == 0 && g_data.gnl_return == 0)
		ft_ctrl_d();
	//splite_cmds = ft_split(g_data.line, ';');
	//lengthcmds = ft_split_length(splite_cmds);
	//i = 0;
	//while (i < lengthcmds)
	//{
	ft_handlecommands(g_data.line);
	//	i++;
	//}
	//ft_free_split(&splite_cmds);
}
