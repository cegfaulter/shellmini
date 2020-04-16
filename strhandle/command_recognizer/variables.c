/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 04:17:19 by mel-omar          #+#    #+#             */
/*   Updated: 2020/03/11 11:31:45 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

int       len_name(char *str)
{
    int     len;

    len = 0;
    if ((str[len] < 'A' || (str[len] > 'Z' && str[len] < 'a') || str[len] > 'z') && str[len] !=  '_')
        return (0);
    len++;
    while (str[len])
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

int        variables(char *dest, char *str, int *iter, t_cmap *map)
{
    int     len;
    int     i;
    char    *var_name;
    char    *value;

    len = len_name(str + 1);
    *iter += len;
    if (!len)
        return (0);
    i = 0;
    var_name = ft_csubstr(str + 1, len);
    value = get(map, var_name);
    free(var_name);
    if (!value)
        return (0);
    len = ft_cstrlen(value);
    while (i < len)
    {
        dest[i] = value[i];
        i++;
    }
    dest[i] = 0;
    return (i);
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
