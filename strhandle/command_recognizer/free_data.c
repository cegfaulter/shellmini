/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:05:47 by mel-omar          #+#    #+#             */
/*   Updated: 2020/03/11 10:06:56 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

void		free_rec(t_rec **rec)
{
	if (*rec)
	{
		clear_list(&(*rec)->files, free);
		clear_list(&(*rec)->oper, free);
		clear_list(&(*rec)->text, free);
	}
}

void	 free_ccommand(void *cmd)
{
	t_ccommand *command;

	command = (t_ccommand *)cmd;
	free(command->cmd);
	free_rec(&command->data);
	free(command);
}

void	free_vars(void *vars)
{
	t_key_value	*k_v;

     k_v = (t_key_value *)vars;
	 free(k_v->key);
	 free(k_v->value);
	 free(k_v);
}

void	free_all_commands(t_clist **lst)
{
	t_clist 	*list;

	if (*lst)
	{
		if ((*lst)->next)
			free_all_commands(&(*lst)->next);
		list = (t_clist *)(*lst)->data;
		clear_list(&list, free_ccommand);
		free(*lst);
		*lst = NULL;
	}
}
