/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:39:33 by settaqi           #+#    #+#             */
/*   Updated: 2019/10/25 10:03:33 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (n == 0)
		return (0);
	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	while (n > 0 && (*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1++ != *s2++)
			return (*(s1 - 1) - *(s2 - 1));
		n--;
	}
	return (0);
}
