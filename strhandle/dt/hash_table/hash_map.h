/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:15:36 by mel-omar          #+#    #+#             */
/*   Updated: 2020/10/14 11:30:45 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_MAP_H
# define HASH_MAP_H
# define SIZE 51

# include "../linkedlist/linkedlist.h"

typedef struct	s_key_value
{
	void		*key;
	void		*value;
}				t_key_value;

typedef struct	s_hash_map
{
	int			size;
	t_clist		*lst[SIZE];
}				t_cmap;

int				get_hash_code(const void *key, size_t key_size);
void			*copy_key(const unsigned char *key, size_t key_size);
t_cmap			*init_map(void);
int				compare(const void *val1, const void *val2, size_t key_size);
t_key_value		*init_kv(void *key, void *value);
void			free_kv(void *k_v);
void			set_value(t_cmap *map, const void *key,
				void *value, size_t key_size);
void			*get_value(t_cmap *map, const void *key, size_t key_size);
t_clist			*get_keys(const t_cmap *map);
void			clear_map(t_cmap **map, void free_data(void *k_v));
void			*pop_value(t_cmap *map, const unsigned char *key
				, size_t key_size);
#endif
