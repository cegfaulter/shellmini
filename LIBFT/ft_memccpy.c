/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:11:33 by settaqi           #+#    #+#             */
/*   Updated: 2019/10/24 10:10:33 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*source;
	char	*dest;

	source = (char*)src;
	dest = (char*)dst;
	if (!dst && !src && !c && !n)
		return (dst);
	if (n > 0)
	{
		while (n > 0)
		{
			if (*source == (char)c)
			{
				*dest = (unsigned char)c;
				return ((void*)++dest);
			}
			*dest++ = (unsigned char)*source++;
			n--;
		}
	}
	if (n == 0)
		return (NULL);
	return (dst);
}
