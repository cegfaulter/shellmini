/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:11:38 by settaqi           #+#    #+#             */
/*   Updated: 2019/10/16 02:39:24 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ptr;
	int		b;

	if (!s)
		return ((char*)s);
	i = ft_strlen((char*)s);
	b = 0;
	if (!(ptr = (char*)malloc((i + 1) * sizeof(char))))
		return (0);
	while (i--)
	{
		ptr[b] = f(b, s[b]);
		b++;
	}
	ptr[b] = '\0';
	return (ptr);
}
