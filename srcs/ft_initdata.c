/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initdata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:25:05 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/26 12:24:47 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_set_homedirectory(void)
{
	if (g_data.home_directory)
	{
		free(g_data.home_directory);
		g_data.home_directory = NULL;
	}
	g_data.home_directory = get(g_map_env, "HOME");
}

void		ft_init_data(int argc, char **argv, char **envp)
{
	ft_set_homedirectory();
	setv(g_map_env, "?", ft_cstrdup("0"));
}
