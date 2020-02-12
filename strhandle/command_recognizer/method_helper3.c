/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_helper3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:15:15 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/11 21:16:02 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

t_rec		*init_rec(void)
{
	t_rec	*rec;

	rec = malloc(sizeof(t_rec));
	rec->files = NULL;
	rec->oper = NULL;
	rec->text = malloc(sizeof(char));
	rec->text[0] = 0;
	return (rec);
}

void		init_condition(int *cond, int size, char *c)
{
	int		iter;

	iter = 0;
	while (iter < size)
	{
		cond[iter] = 0;
		iter++;
	}
	*c = 0;
}

void		display_data(void *data)
{
	print("%s ", (char *)data);
}

void		print_rec(t_rec *rec)
{
	print("\n**********************************************\n");
	print("oper------------------------------------------\n");
	iterate_list(rec->oper, display_data);
	print("\n");
	print("files-----------------------------------------\n");
	iterate_list(rec->files, display_data);
	print("\n");
	print("texts-----------------------------------------\n");
	print("%s", rec->text);
	print("\n**********************************************\n");
}
