/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 03:21:14 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/21 11:10:42 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo_builtins(t_command *item, int c)
{
	char	**command_line;
	int		i;
	int		newline;
	int		len;

	i = 1;
	newline = 1;
	if (c == 1)
	{
		command_line = item->command;
		while (ft_strcmp("-n", command_line[i]) == 0)
		{
			newline = 0;
			i++;
		}
		len = ft_split_length(command_line);
		while (i < len)
		{
			ft_putstr_fd(command_line[i], 1);
			if (command_line[i + 1] != 0)
				ft_putchar_fd(' ', 1);
			i++;
		}
		if (newline)
			ft_putchar_fd('\n', 1);
	}
}
