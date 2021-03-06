/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:55:40 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/26 13:13:55 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		white_digit(int c, int d)
{
	if (d == 0)
	{
		if (c == '\n' || c == '\t' || c == '\v' || c == ' '
		|| c == '\f' || c == '\r')
			return (1);
		return (0);
	}
	return (-1);
}

int		checkoverint(long long number, int sym)
{
	if (sym == 2)
		number *= -1;
	if ((number) / 10 > 9223372036854775807)
		return (-1);
	else if ((number) / 10 < -2147483648)
		return (0);
	return (-33);
}

int		ft_atoi(const char *str)
{
	long	number;
	int			c;

	number = 0;
	c = 0;
	if (*str == '\0')
		return (0);
	while (white_digit(*str, 0) == 1)
		str++;
	if (*str == '-')
		c = 2;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0' && *str <= '9' && *str >= '0')
	{
		number += *str - '0';
		number *= 10;
		if (checkoverint(number, c) != -33)
		 	return ((int)checkoverint(number, c));
		str++;
	}
	if (c == 2)
		number *= -1;
	return (number / 10);
}
