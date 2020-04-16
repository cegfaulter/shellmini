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

void		free_keys_rec(void *k_v)
{
	t_rec			*value;
	char			*key;
	t_key_value		*key_value;

	key_value = (t_key_value *)k_v; 
	key  = (char *)key_value->key;
	value = (t_rec *)key_value->value;
	free(key);
	free_rec(&value);
	free(key_value);
}

void	 free_ccommand(void *cmd)
{
	t_ccommand *command;

	command = (t_ccommand *)cmd;
	free(command->keys);
	clear_map(&command->full_command, free_keys_rec);
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
	clear_list(lst, free_ccommand);
}
