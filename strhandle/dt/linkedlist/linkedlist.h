/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:36:38 by mel-omar          #+#    #+#             */
/*   Updated: 2020/10/26 10:17:38 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include <stdlib.h>

typedef struct		s_clist
{
	void			*data;
	struct s_clist	*next;
}					t_clist;

char				**g_reserved;

void				*free_node(t_clist **list);
void				append(t_clist **list, void *data);
void				*pop(t_clist **list);
void				iterate_list(const t_clist *list, void func(void *data));
void				clear_list(t_clist **list, void free_data(void *data));
size_t				length(const t_clist *lst);
int					check_reserved_key(char *key);

#endif
