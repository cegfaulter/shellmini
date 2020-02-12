/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:29:19 by settaqi           #+#    #+#             */
/*   Updated: 2019/10/19 23:48:24 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		*head;
	t_list		*savenextaadd;

	head = *lst;
	while (head)
	{
		savenextaadd = head->next;
		ft_lstdelone(head, del);
		head = savenextaadd;
	}
	*lst = NULL;
}
