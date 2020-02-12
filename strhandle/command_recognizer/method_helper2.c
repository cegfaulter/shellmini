/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_helper2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:23:45 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/12 18:37:23 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

int			get_operator(t_rec *rec, char *str, int *is_)
{
	int		iter;
	int		i;
	char	c;

	i = 0;
	iter = 0;
	while (str[i] == ' ')
		i++;
	if (in_set(str[i], "><"))
	{
		c = str[i];
		iter = 1;
		while (str[i + iter] == c)
			iter++;
		append(&rec->oper, ft_csubstr(str + i, iter));
		is_[0] = 1;
	}
	return (i + iter);
}

int			get_files(t_rec *rec, char *str, char *ignored, int *is_)
{
	int		i;
	int		iter;

	i = 0;
	while (str[i] == ' ' && !*ignored)
		i++;
	iter = 0;
	while ((str[i + iter] != ' ' || *ignored) && str[i + iter])
	{
		if (in_set(str[i + iter], "\"'"))
			switcher(str[i + iter], ignored);
		iter++;
	}
	append(&rec->files, ft_csubstr(str + i, iter));
	i += iter;
	is_[0] = 0;
	return (i);
}

int			get_text(t_rec *rec, char *str, char *ignored)
{
	int		i;
	int		iter;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (in_set(str[i], "<>"))
		return (i);
	iter = 0;
	while ((str[i + iter] != ' ' || *ignored) && str[i + iter])
	{
		if (in_set(str[i + iter], "\"'"))
			switcher(str[i + iter], ignored);
		iter++;
	}
	if (iter > 0)
		rec->text = ft_cstrjoin(rec->text, ft_csubstr(str + i, iter));
	else
		rec->text = ft_cstrjoin(rec->text, NULL);
	i += iter;
	return (i);
}

int			in_set(char c, char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

void		switcher(char s, char *ignored)
{
	if (*ignored == s)
		*ignored = 0;
	else if (!(*ignored))
		*ignored = s;
}
