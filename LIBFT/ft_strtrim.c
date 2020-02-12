/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:10:33 by settaqi           #+#    #+#             */
/*   Updated: 2019/10/19 23:53:01 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_trimfrmstart(char const *set, char const *s1)
{
	int		i;
	int		b;
	int		c;

	i = 0;
	c = 0;
	while (s1[i])
	{
		c = 0;
		b = 0;
		while (set[b])
		{
			if (set[b] == s1[i])
				c = 1;
			b++;
		}
		i++;
		if (c == 0)
			return (i);
	}
	return (0);
}

static int		ft_trimfrmlast(char const *set, char const *s1)
{
	int		i;
	int		b;
	int		c;

	i = ft_strlen(s1);
	c = 0;
	while (i - 1 > 0)
	{
		c = 0;
		b = 0;
		while (set[b])
		{
			if (set[b] == s1[i - 1])
				c = 1;
			b++;
		}
		i--;
		if (c == 0)
			return (i);
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		length;
	char		*ptr;
	int			start;
	int			end;
	int			i;

	if (!s1 || !set)
		return (0);
	length = ft_strlen(s1);
	start = ft_trimfrmstart(set, s1) - 1;
	end = ft_trimfrmlast(set, s1);
	ptr = (char*)malloc((end - start + 2) * sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	while (start <= end)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}
