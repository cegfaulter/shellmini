/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:05:44 by mel-omar          #+#    #+#             */
/*   Updated: 2020/10/21 11:28:26 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

static unsigned int		check_command(const char *text,
							int *error, const char *forbidden)
{
	unsigned int		counter;

	*error = 0;
	counter = 0;
	while (text[counter])
	{
		if (forbidden && in_set(text[counter], (char *)forbidden))
		{
			*error = -1;
			while (text[counter] && in_set(text[counter], (char *)forbidden))
				counter++;
			return (counter);
		}
		else if (text[counter] == '=')
		{
			return (counter);
		}
		counter++;
	}
	*error = 1;
	return (counter);
}

static void				invalid_context(const char *text, unsigned int counter)
{
	unsigned int		iter;

	iter = 0;
	while (iter < counter)
	{
		write(1, &text[iter], 1);
		iter++;
	}
	write(1, "\n", 1);
}

char					**split_export(const char *text, const char *forbidden)
{
	int					error;
	unsigned int		count;
	char				**tuple;

	count = check_command(text, &error, (char *)forbidden);
	if (error == -1)
	{
		return (NULL);
	}
	if (!(tuple = malloc(sizeof(char *) * 2)))
		return (NULL);
	if (error == 1)
	{
		tuple[0] = ft_cstrdup((char *)text);
		tuple[1] = ft_cstrdup("");
	}
	else
	{
		tuple[0] = ft_csubstr((char *)text, count);
		tuple[1] = ft_csubstr((char *)&text[count + 1], ft_cstrlen(text));
	}
	return (tuple);
}
