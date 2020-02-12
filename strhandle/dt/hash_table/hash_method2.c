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
