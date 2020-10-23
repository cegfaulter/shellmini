/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 04:17:19 by mel-omar          #+#    #+#             */
/*   Updated: 2020/10/23 11:30:19 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"
#include <stdio.h>

int       len_name(char *str)
{
    int     len;

    len = 0;
    
    if ((str[len] < 'A' || (str[len] > 'Z' && str[len] < 'a') || str[len] > 'z') && str[len] !=  '_' && str[len] != '\n' && str[len])
    {
        if (str[len] >= '0' && str[len] <= '9')
            return (1);
        return (0);
    }
    while (str[len] && str[len] != '\n')
    {
        if  (str[len] < '0' || (str[len] > '9' && str[len] < 'A'))
            break;
        else if (((str[len] > 'Z' && str[len] < 'a') || str[len] > 'z') && str[len] !=  '_')
            break;
        len++;
    }
    return (len);
}

int      var_len(char *str, int *iter, t_cmap *map)
{
    int     len;
    char    *var;

    str++;
    len = len_name(str);
    if (!len)
        return (0);
    var = ft_csubstr(str, len);
    *iter += len;
    len = ft_cstrlen(get(map, var));
    free(var);
    return (len);
}

int	   copy_vars(char *dest, char *src, int len)
{
	int 	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (len);
}

int        variables(char *dest, char *str, int *iter, t_cmap *map)
{
    int     len;
    char    *var_name;
    char    *value;

    len = len_name(str + 1);
    *iter += len;
    if (len > 0)
    {
	    var_name = ft_csubstr(str + 1, len);
	    value = get(map, var_name);
	    len = ft_cstrlen(value);
	    free(var_name);
	    len = ft_cstrlen(value);
	    return (copy_vars(dest, value, len));
    }
    return (copy_vars(dest, "$", 1));
}

t_cmap     *put_vars(char **vars)
{
    int         iter;
    char        **sp;
    t_cmap      *map;

    map = init_map();
    iter = 0;
    while (vars[iter])
    {
        sp = csplit(vars[iter], '=');
        setv(map, sp[0], ft_cstrdup(sp[1]));
        free_split(&sp);
        iter++;
    }
    return (map);
}
