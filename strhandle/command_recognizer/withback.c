/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   withback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 03:37:08 by mel-omar          #+#    #+#             */
/*   Updated: 2020/03/11 03:48:00 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"


static int        back_slash_len(char *str, t_cmap *map)
{
    int     len;
    int     iter;
    int     back_slash;

    len = 0;
    iter = 0;
    back_slash = 0;
    while (str[iter])
    {
        if (str[iter] == '\\' && back_slash % 2 == 0)
            back_slash++;
        else if (back_slash % 2)
        {
            len++;
            back_slash++;
        }
        else if (back_slash % 2 == 0 &&  in_set(str[iter], "\"'>< "))
            break;
        else if (back_slash % 2 == 0 && str[iter] == '$')
            len += var_len(str + iter, &iter, map);
        else if (back_slash % 2 == 0)
            len++;
        iter++;
    }
    return (len);
}

static void     withback_helper(char *s, char c, int *i, int *back)
{
    s[*i] = c;
    (*i)++;
    (*back)++;
}

static void     withback_helper2(char *s, char c, int *i)
{
    s[*i] = c;
    (*i)++;
}

char            *withback(char *str, t_cmap *map, int *iter)
{
    int     i;
    int     len;
    int     back_slash;
    char    *s;

    i = 0;
    len = back_slash_len(str + *iter, map);
    s = malloc(sizeof(char) * (len + 1));
    back_slash = 0;
    while (str[*iter])
    {
        if (str[*iter] == '\\' && back_slash % 2 == 0)
            back_slash++;
        else if (back_slash % 2)
            withback_helper(s, str[*iter], &i, &back_slash);
        else if (back_slash % 2 == 0 && in_set(str[*iter], "\"'>< "))
            break;
        else if (back_slash % 2 == 0 && str[*iter] == '$')
            i += variables(s + i, str + *iter, iter, map);
        else if (back_slash % 2 == 0)
            withback_helper2(s, str[*iter], &i);
        (*iter)++;
    }
    s[i] = 0;
    return (s);
}