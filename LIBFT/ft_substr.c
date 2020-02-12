/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:44:46 by settaqi           #+#    #+#             */
/*   Updated: 2019/10/18 22:48:18 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*str;
	char	*substring;
	int		i;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		len = 0;
	str = (char*)s;
	if (!(substring = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (len)
	{
		substring[i++] = str[start++];
		len--;
	}
	substring[i] = '\0';
	return (substring);
}
