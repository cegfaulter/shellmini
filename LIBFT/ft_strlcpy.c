/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:54:37 by settaqi           #+#    #+#             */
/*   Updated: 2019/10/21 03:37:12 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char	*string;
	char	*desti;
	int		i;

	string = (char*)src;
	desti = dest;
	i = 0;
	if (size == 0)
		return (ft_strlen(string));
	while (size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
		size--;
	}
	desti[i] = '\0';
	return (ft_strlen(string));
}
