/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:59:55 by settaqi           #+#    #+#             */
/*   Updated: 2019/10/16 02:43:43 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (!s1 || !s2)
		return (0);
	string = (char*)malloc((ft_strlen((char*)s1) +
				ft_strlen((char*)s2)) * sizeof(char));
	if (!string)
		return (0);
	while (s1[c])
		string[i++] = s1[c++];
	c = 0;
	while (s2[c])
		string[i++] = s2[c++];
	string[i] = '\0';
	return (string);
}
