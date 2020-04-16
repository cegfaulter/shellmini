/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 03:48:49 by mel-omar          #+#    #+#             */
/*   Updated: 2020/03/11 08:31:48 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

static int        double_quotes_back(char *s, t_cmap *map)
{
    int     len;
    int     iter;
    int     lock;

    len = 0;
    iter = -1;
    while (s[++iter] != 0)
    {
        if (s[iter] == '"' && lock)
            break ;
        if (s[iter] == '\\' && in_set(s[iter + 1], "$\"") && lock)
        {
            lock = 0;
            continue;
        }
        if (s[iter] == '$' && lock)
            len += var_len(s + iter, &iter, map);
        else
            len++;
        lock = 1;
    }
    return (len);
}

static void     init_vars(int *i, int *i1, int *i2)
{
    *i = 0;
    *i1 = -1;
    *i2 = 1;
}

static void     double_quotes_helper(char *s, int *i, char c)
{
    s[*i] = c;
    (*i)++;
}

static char     *double_quotes_helper2(char *s, int *i, int iter2, int iter)
{
    *i += iter;
    s[iter2] = 0;
    return (s);
}

char            *double_quotes(char *str, int *i, t_cmap *map)
{
    char        *s;
    int         len;
    int         iter;
    int         iter2;
    int         lock;

    len = double_quotes_back(str + *i, map);
    s = malloc(sizeof(char) * (len + 1));
    init_vars(&iter2, &iter, &lock);
    while (str[++iter + *i] != 0)
    {
        if (str[iter + *i] == '"' && lock)
            break ;
        if (str[iter + *i] == '\\' && in_set(str[iter + 1 + *i], "$\"\\") && lock)
            lock = 0;
        else
        {
            if (str[iter + *i] == '$' && lock)
                iter2 += variables(s  + iter2, str + iter + *i, &iter, map);
            else
                double_quotes_helper(s, &iter2, str[iter + *i]);
            lock = 1;
        }
    }
    return (double_quotes_helper2(s, i, iter2, iter));
}
