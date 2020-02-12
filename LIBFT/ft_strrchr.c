/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:04:11 by settaqi           #+#    #+#             */
/*   Updated: 2019/10/20 20:33:39 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*string;

	i = 0;
	string = (char*)str;
	while (*string)
	{
		i++;
		string++;
	}
	while (i >= 0)
	{
		if (*string == c)
			return ((char*)string);
		string--;
		i--;
	}
	return (0);
}
