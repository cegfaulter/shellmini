/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:56:22 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/12 16:01:56 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int		print(char *format, ...)
{
	va_list		ap;
	t_flags		flag;

	g_len = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			init_flags(&flag);
			check_flags(&format, &flag);
			apply_flags(&flag, &ap);
		}
		else
		{
			ft_cputchar(*format);
			format++;
		}
	}
	return (g_len);
}
