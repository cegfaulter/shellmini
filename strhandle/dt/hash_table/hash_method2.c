/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_method2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:17:26 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/12 16:09:46 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"
#include <stdio.h>

t_clist		*get_keys(const t_cmap *map)
{
	t_clist			*list;
	t_clist			*lst;
	int				iter;
	unsigned char	*key;

	iter = 0;
	list = NULL;
	while (iter < SIZE)
	{
		lst = map->lst[iter];
		while (lst)
		{
			key = ((t_key_value *)lst->data)->key;
			append(&list, key);
			lst = lst->next;
		}
		iter++;
	}
	return (list);
}

void		*copy_key(const unsigned char *key, size_t key_size)
{
	size_t			iter;
	unsigned char	*dst;

	iter = 0;
	dst = malloc(key_size + 1);
	while (iter < key_size)
	{
		dst[iter] = key[iter];
		iter++;
	}
	dst[iter] = 0;
	return (dst);
}

void		*pop_value(t_cmap *map, const unsigned char *key, size_t key_size)
{
	int 			backet_id;
	t_clist			*list;
	t_clist 		*before;
	void 			*value;

	backet_id = get_hash_code(key, key_size);
	list = map->lst[backet_id];
	before = NULL;
	while (list)
	{
		if (compare(((t_key_value *)list->data)->key, key, key_size))
		{
			if (before)
				before->next = list->next;
			else
				map->lst[backet_id] = list->next;
			value = ((t_key_value *)list->data)->value;
			free(((t_key_value *)list->data)->key);
			free(list);
			return (value);
		}
		before = list;
		list = list->next;
	}
	return (NULL);
}