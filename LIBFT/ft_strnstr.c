/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:22:23 by settaqi           #+#    #+#             */
/*   Updated: 2019/10/24 10:07:02 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*checkerwh(const char *str, const char *needle, size_t len)
{
	int		i;
	int		b;

	i = 0;
	while (i < (int)len && str[i] != '\0')
	{
		b = 0;
		if (str[i] == needle[b])
		{
			if (ft_strlen(needle) + i > len)
				return (0);
			else
			{
				if (!ft_strncmp(str + i, needle, ft_strlen(needle)))
					return ((char*)str + i);
			}
		}
		i++;
	}
	return (0);
}

char		*ft_strnstr(const char *str, const char *needle, size_t len)
{
	int			i;
	char		*ptr;

	i = 0;
	if (*needle == '\0' || needle == NULL)
		return ((char*)str);
	if (!len && !str)
		return (0);
	ptr = checkerwh(str, needle, len);
	return (ptr);
}
