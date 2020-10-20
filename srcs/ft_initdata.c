/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initdata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:25:05 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/15 11:30:38 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_set_homedirectory(void)
{
	int		i;
	char	*home_directory;
	char	**splitted_data;

	home_directory = NULL;
	g_data.home_directory = get(g_map_env, "HOME");
}

void		ft_init_data(int argc, char **argv, char **envp)
{
	ft_set_homedirectory();
}
