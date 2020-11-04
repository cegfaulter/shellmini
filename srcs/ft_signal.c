/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 23:01:58 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/26 12:54:10 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_ctrl_c(int signal)
{
	print("\n");
	print_shell_line();
}

void		ft_ctrl_backslash(int signal)
{
	printf("ctrl + \\\n");
}

void		ft_signal(void)
{
	signal(SIGINT, &ft_ctrl_c);
	signal(SIGQUIT, &ft_ctrl_backslash);
}