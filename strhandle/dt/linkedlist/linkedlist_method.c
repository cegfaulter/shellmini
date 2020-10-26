/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_method.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:37:32 by mel-omar          #+#    #+#             */
/*   Updated: 2020/10/26 10:17:44 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include "../../../minishell.h"

void	append(t_clist **list, void *data)
{
	t_clist	*temp;
	t_clist	*before;

	temp = malloc(sizeof(t_clist));
	temp->data = data;
	temp->next = NULL;
	if (!(*list))
		*list = temp;
	else
	{
		before = *list;
		while (before->next)
			before = before->next;
		before->next = temp;
	}
}

void	*pop(t_clist **list)
{
	void	*data;
	t_clist	*before;
	t_clist	*temp;

	data = NULL;
	if (!(*list))
		return (data);
	if (!((*list)->next))
		data = free_node(list);
	else
	{
		before = (*list)->next;
		temp = *list;
		while (before->next)
		{
			temp = before;
			before = before->next;
		}
		temp->next = NULL;
		data = free_node(&before);
	}
	return (data);
}

void	iterate_list(const t_clist *list, void func(void *data))
{
	t_clist	*temp;

	temp = (t_clist *)list;
	while (temp)
	{
		func(temp->data);
		temp = temp->next;
	}
}

void	clear_list(t_clist **list, void free_data(void *data))
{
	if (!*list)
		return ;
	if ((*list)->next)
		clear_list(&((*list)->next), free_data);
	if (free_data)
	{
		free_data((*list)->data);
		(*list)->data = NULL;
	}
	free(*list);
	*list = NULL;
}

size_t	length(const t_clist *list)
{
	size_t	len;
	t_clist	*lst;

	lst = (t_clist *)list;
	len = 0;
	while (lst)
	{
		if (check_reserved_key(lst->data))
			len++;
		lst = lst->next;
	}
	return (len);
}
