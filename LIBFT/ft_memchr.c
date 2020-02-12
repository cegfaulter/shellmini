/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:46:23 by settaqi           #+#    #+#             */
/*   Updated: 2019/10/24 08:55:46 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*string;

	string = (unsigned char*)str;
	if (n > 0)
	{
		while (n > 0)
		{
			if (*string == (unsigned char)c)
				return ((void*)string);
			string++;
			n--;
		}
	}
	return (NULL);
}
