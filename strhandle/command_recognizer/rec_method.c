/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_method.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:02:30 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/12 16:25:24 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

char		*get_command(char **str)
{
	char	*command;
	int		len;
	char	*new_str;
	int		iter;

	len = 0;
	while (**str == ' ')
		(*str)++;
	while ((*str)[len] != ' ' && (*str)[len])
		len++;
	new_str = malloc(sizeof(char) * (len + 1));
	iter = -1;
	while (++iter < len)
	{
		new_str[iter] = **str;
		(*str)++;
	}
	return (new_str);
}

t_rec		*get_data(char *str, int i)
{
	char	ignored;
	char	c;
	int		is_[3];
	int		iter;
	t_rec	*rec;

	init_condition(is_, 3, &ignored);
	rec = init_rec();
	while (str[i])
	{
		i += get_operator(rec, str + i, is_);
		if (is_[0])
			i += get_files(rec, str + i, &ignored, is_);
		if (!is_[0])
			i += get_text(rec, str + i, &ignored);
	}
	return (rec);
}

void		ft_set_command(t_cmap *cd, char *key, t_rec *value)
{
	set_value(cd, key, value, ft_cstrlen(key));
}

t_rec		*get_cdata(t_cmap *cd, char *key)
{
	t_rec	*value;

	value = (t_rec *)get_value(cd, key, ft_cstrlen(key));
	return (value);
}

t_cmap		*get_cmd_data(char *str)
{
	t_cmap	*cmd_data;
	t_rec	*data;
	char	*command;
	char	**spliter;

	spliter = ft_csplit(str, '|', "\"'");
	cmd_data = init_map();
	while (*spliter)
	{
		command = get_command(spliter);
		data = get_data(*spliter, 0);
		ft_set_command(cmd_data, command, data);
		spliter++;
	}
	return (cmd_data);
}
