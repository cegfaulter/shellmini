/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:45:40 by settaqi           #+#    #+#             */
/*   Updated: 2019/10/19 23:48:10 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list		*head;
	t_list		*newnode1;
	t_list		*newnode2;
	t_list		*headofnewnode;

	head = lst;
	headofnewnode = NULL;
	if (!(newnode1 = ft_lstnew(NULL)))
		return (0);
	headofnewnode = newnode1;
	while (head)
	{
		newnode1->content = f(head->content);
		if (!(newnode2 = ft_lstnew(NULL)))
		{
			ft_lstclear(&headofnewnode, del);
			return (0);
		}
		newnode1->next = newnode2;
		newnode1 = newnode1->next;
		head = head->next;
	}
	return (headofnewnode);
}
