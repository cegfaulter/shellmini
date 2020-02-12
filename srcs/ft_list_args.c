/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 03:08:32 by settaqi           #+#    #+#             */
/*   Updated: 2020/01/31 15:32:57 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void			ft_oldargsvalues(void)
{
	t_list		*tmp;
	int			i;

	i = 0;
	tmp = g_args.list_args;
	while (tmp)
	{
		while (((char*)tmp->content)[i])
		{
			if (((char*)tmp->content)[i] == -1)
				((char*)tmp->content)[i] = ' ';
			if (((char*)tmp->content)[i] == -2)
				((char*)tmp->content)[i] = ';';
			if (((char*)tmp->content)[i] == -3)
				((char*)tmp->content)[i] = '>';
			if (((char*)tmp->content)[i] == -4)
				((char*)tmp->content)[i] = '<';
			if (((char*)tmp->content)[i] == -5)
				((char*)tmp->content)[i] = '|';
			i++;
		}
		tmp = tmp->next;
	}
}
