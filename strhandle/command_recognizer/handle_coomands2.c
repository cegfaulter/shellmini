/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_coomands2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 07:12:10 by mel-omar          #+#    #+#             */
/*   Updated: 2020/04/29 23:07:52 by elomary00        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

t_clist  *get_commands(char *cmd, t_cmap *envs)
{
    t_clist  *cmds;

    cmds = NULL;
    append(&cmds, get_command_line(cmd, envs));
    return (cmds);
}


