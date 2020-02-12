/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:34:20 by settaqi           #+#    #+#             */
/*   Updated: 2019/10/22 13:16:01 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*source;
	char	*desti;
	int		i;
	int		c;
	int		k;

	source = (char*)src;
	desti = dest;
	if ((size == 0 && dest == NULL))
		return (ft_strlen(src));
	k = ft_strlen(desti);
	if (size > (size_t)k)
		i = ft_strlen(dest) + ft_strlen(src);
	else
		i = ft_strlen(src) + size;
	c = 0;
	while (source[c] != '\0' && k < (int)size - 1)
	{
		desti[k] = source[c];
		c++;
		k++;
	}
	if (c > 0)
		desti[k] = '\0';
	return ((size_t)i);
}
