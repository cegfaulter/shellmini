/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:42:15 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/20 10:44:52 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit(int c)
{
	if (c == 1)
		ft_putstr_fd("exit", 2);
	else
		exit(0);
}