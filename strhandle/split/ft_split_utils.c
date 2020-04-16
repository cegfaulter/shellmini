/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:52:22 by mel-omar          #+#    #+#             */
/*   Updated: 2020/03/09 02:18:40 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

void	set(char *to_split, char c, char *s, char sp)
{
	if (!s)
		return ;
	while (*s)
	{
		if (*s == c)
		{
			if (*to_split == c && *to_split != '\\')
				*to_split = 0;
			else if (!*to_split)
				*to_split = c;
		}
		else if (*to_split == '\\' && c != sp)
		{
			*to_split = 0;
			break ;
		}
		s++;
	}
}
