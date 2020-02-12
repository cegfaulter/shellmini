/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:34:33 by settaqi           #+#    #+#             */
/*   Updated: 2019/10/24 08:58:39 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src1;
	char	*dst1;

	if (!dst && !src)
		return (0);
	if (len == 0)
		return (dst);
	if (src < dst)
	{
		src1 = (char*)src + (len - 1);
		dst1 = (char*)dst + (len - 1);
		while (len--)
			*dst1-- = *src1--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
