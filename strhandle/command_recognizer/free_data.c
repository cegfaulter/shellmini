/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:05:47 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/12 16:20:11 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

void		free_list_data(void *data)
{
	char	*dt;

	dt = (char *)data;
	free(dt);
}

void		free_rec(t_rec **rec)
{
	clear_list(&(*rec)->oper, free_list_data);
	clear_list(&(*rec)->files, free_list_data);
	free((*rec)->text);
	free(*rec);
	*rec = NULL;
}

void		free_data(void *kv)
{
	t_key_value		*key_value;
	t_rec			*value;

	key_value = (t_key_value *)kv;
	free((char *)key_value->key);
	value = (t_rec *)key_value->value;
	free_rec(&value);
	free(key_value);
}

void		free_cmd_data(t_cmap **cmd_data)
{
	clear_map(cmd_data, free_data);
}

void		free_keys(t_clist **keys)
{
	free(*keys);
	*keys = NULL;
}
