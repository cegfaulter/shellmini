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
							int *error, const char *forbidden, unsigned int *after)
{
	unsigned int		counter;

	*error = 0;
	counter = 0;
	if (text[0] >= '0' && text[0] <= '9')
		*error = -1;
	while (text[counter] && *error != -1)
	{
		if (forbidden && in_set(text[counter], (char *)forbidden))
		{
			*error = -1;
			while (text[counter] && in_set(text[counter], (char *)forbidden))
				counter++;
			return (counter);
		}
		else if (text[counter] == '=' && counter > 0)
		{
			*after = 1;
			if (text[counter - 1] == '+')
			{
				*after = 2;
				return (counter - 1);
			}
			return (counter);
		}
		else if (text[counter] == '+')
		{
			if (text[counter + 1] != '=') {
				*error = -1;
				return (counter);
			}
		}
		counter++;
	}
	*error = -1;
	return (counter);
}

char					**split_export(const char *text, const char *forbidden)
{
	int					error;
	unsigned int		count;
	char				**tuple;
	unsigned int		after;

	after = 0;
	count = check_command(text, &error, (char *)forbidden, &after);
	if (error == -1)
	{
		return (NULL);
	}
	if (!(tuple = (char**)malloc(sizeof(char *) * 2)))
		return (NULL);
	if (error == 1)
	{
		tuple[0] = ft_cstrdup((char *)text);
		tuple[1] = ft_cstrdup("");
	}
	else
	{
		tuple[0] = ft_csubstr((char *)text, count);
		tuple[1] = ft_csubstr((char *)&text[count + after], ft_cstrlen(text));
	}
	return (tuple);
}
