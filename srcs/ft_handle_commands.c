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

void		ft_handlecommands(char *cmd)
{
	t_cmap		*cmds;
	t_clist		*iter_key;
	t_clist		*keys;
	t_rec		*rec;

	cmds = get_cmd_data(cmd);
	keys = get_keys(cmds);
	iter_key = keys;
	while (iter_key)
	{
		print("key = %s\n", (char *)iter_key->data);
		rec = get_cdata(cmds, (char *)iter_key->data);
		print_rec(rec);
		iter_key = iter_key->next;
	}
}

void		ft_commands_line(void)
{
	char	**splite_cmds;
	int		lengthcmds;
	char	**data_splitted;
	int		i;

	if (*(g_data.line) == 0 && g_data.gnl_return == 0)
		ft_ctrl_d();
	splite_cmds = ft_split(g_data.line, ';');
	lengthcmds = ft_split_length(splite_cmds);
	i = 0;
	while (i < lengthcmds)
	{
		ft_handlecommands(splite_cmds[i]);
		i++;
	}
	ft_free_split(&splite_cmds);
}
