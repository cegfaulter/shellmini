/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:05:21 by mel-omar          #+#    #+#             */
/*   Updated: 2020/03/08 23:28:49 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

/*
void		display_map(t_cmap *map)
{
	t_clist		*keys;
	t_clist		*iter_key;

	keys = get_keys(map);
	print("%d\n",  length(keys));
	iter_key = keys;
	while (iter_key)
	{
		print("key: %s\nvalue: >>>\n", (char *)iter_key->data);
		print_rec(get_cdata(map, (char *)iter_key->data));
		iter_key = iter_key->next;
		print("\n\n");
	}
	free_keys(&keys);
}

int			main(void)
{
	char		*str = "echo text >file2             >file3";
	t_cmap		*cmd_data;
	t_clist		*keys;

	cmd_data = get_cmd_data(str);
	display_map(cmd_data);
	return (0);
}
*/