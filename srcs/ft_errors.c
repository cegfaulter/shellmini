/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 08:38:18 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/21 13:52:05 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_strerror(char *str)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
}

void		ft_print_error(void)
{
	if (g_data.error_detected == 2)
		ft_strerror("no output file");
	else if (g_data.error_detected == 5)
		ft_strerror("syntax error near unexpected token `|'");
	else if (g_data.error_detected == 6)
		ft_strerror("syntax error near unexpected token `||'");
	else if (g_data.error_detected == 7)
		ft_strerror("syntax error near unexpected token `;;'");
	else if (g_data.error_detected == 8)
		ft_strerror("syntax error near unexpected token `;'");
	else
		ft_strerror(strerror(errno));
}
