/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 00:32:48 by settaqi           #+#    #+#             */
/*   Updated: 2019/10/24 09:10:17 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = 0;
	if (!(ptr = (void*)malloc(count * size)))
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
