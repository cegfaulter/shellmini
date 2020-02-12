/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:53:12 by settaqi           #+#    #+#             */
/*   Updated: 2019/10/24 10:17:47 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*source;
	char	*dest;

	source = (char*)src;
	dest = (char*)dst;
	if ((dst == NULL && src == NULL) || ft_memcmp(dst, src, n) == 0)
		return (dst);
	if (n > 0)
	{
		while (n > 0)
		{
			*dest++ = *source++;
			n--;
		}
	}
	return (dst);
}
