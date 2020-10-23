/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:10:49 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/23 19:26:30 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		print_env(char **env_2d)
{
	int		i;

	i = 0;
	while (env_2d[i])
	{
		ft_putstr_fd(env_2d[i++], 1);
		ft_putstr_fd("\n", 1);
	}
}

char		**update_print_env(int c)
{
	char	**env_2d;

	env_2d = from_map_to_arr(g_map_env, 2);
	if (c == 1)
		print_env(env_2d);
	return (env_2d);
}
