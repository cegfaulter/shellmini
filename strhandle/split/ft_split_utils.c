/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:52:22 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/08 18:03:59 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

void	set(char *to_split, char c, char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		if (*s == c)
		{
			if (*to_split == c)
				*to_split = 0;
			else if (!*to_split)
				*to_split = c;
		}
		s++;
	}
}
