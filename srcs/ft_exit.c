/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:42:15 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/26 12:55:14 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_isdigit_up(int c)
{
	if (ft_isdigit(c) || c == '-' || c == '+')
		return (1);
	return (0);
}

int		ft_in_set_ref(char *search, int func(int c))
{
	int		i;

	i = 0;
	while (search[i])
	{
		if (!func(search[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*ft_status(t_command *item)
{
	if (ft_split_length(item->command) > 2)
		return ("1");
	else if (ft_split_length(item->command) == 2)
	{
		if (!ft_in_set_ref(item->command[1], ft_isdigit_up))
			return ("255");
		return (item->command[1]);
	}
	return (get(g_map_env, "?"));
}

void	ft_exit(t_command *item, int c)
{
	int		status;

	status = ft_atoi(get(g_map_env, "?"));
	if (c == 1)
		ft_putstr_fd("exit", 2);
	else if(status > 0)
		exit(status);
	else
		exit(ft_atoi(ft_status(item)));
}
