/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_coomands2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 07:12:10 by mel-omar          #+#    #+#             */
/*   Updated: 2020/03/11 07:12:52 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

t_ccommand  *get_command_key_val(char *cmd, t_cmap *envs)
{
    t_ccommand  *key_val;

    key_val = malloc(sizeof(t_ccommand));
    key_val->keys = NULL;
    key_val->full_command = get_command_line(cmd, envs, &key_val->keys);
    return (key_val);
}

t_clist     *all_commands(char *s, char **envs)
{
    t_clist     *all;
    t_cmap      *global_env;
    char        **cmds;
    int         iter;

    global_env = put_vars(envs);
    all = NULL;
    cmds = csplit(s, ';');
    iter = 0;
    while (cmds[iter])
    {
        append(&all, get_command_key_val(cmds[iter], global_env));
        iter++;
    }
    free_split(&cmds);
    clear_map(&global_env, free_vars);
    return (all);
}