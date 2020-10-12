/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_method.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:02:30 by mel-omar          #+#    #+#             */
/*   Updated: 2020/03/11 07:07:22 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

char        *get(t_cmap *map, const char *key)
{
    return ((char *)get_value(map, key, ft_cstrlen(key)));
}

void        setv(t_cmap *map, const char *key, char *value)
{
    char    *val;

    val = get(map, key);
    if (val)
        free(val);
    set_value(map, key, value, ft_cstrlen(key));
}

void        popv(t_cmap *map, const char *key)
{
    char  *value;

    value = pop_value(map, (const unsigned char *)key, ft_cstrlen(key));
    if (value)
        free(value);
}

int			in_set(char c, char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}