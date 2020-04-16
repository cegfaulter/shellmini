/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 21:26:55 by mel-omar          #+#    #+#             */
/*   Updated: 2020/03/11 11:20:59 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

static int        count_word(const char *str, char c, int  is_back)
{
    char        special_char;
    int         looked;
    int         count;
    int         iter;

    looked = 1;
    count = 0;
    special_char = 0;
    iter = 0;
    while (str[iter])
    {
        check_special(str[iter], &special_char, &is_back, str[iter - 1]);
        if ((str[iter] == c && !is_back) && !special_char)
            looked = 1;
        if (looked)
        {
            while (str[iter] == c)
                iter++;
            if (!str[iter])
                break;
            looked = 0;
            count++;
        }
        iter++;
    }
    return (count);
}

static int     *get_length_substrings(const char *str, int c, int wc, int is_back)
{
    int     *arr;
    int     iter;
    int     len;
    int     iter_arr;
    char    special;

    arr = malloc(sizeof(int) * wc);
    iter  = 0;
    iter_arr = -1;
    special = 0;
    while (str[iter])
    {
        len = 0;
        while (str[iter] == c)
            iter++;
        while ((str[iter] != c || is_back || special) && str[iter])
        {
            len++;
            iter++;
            check_special(str[iter], &special, &is_back, str[iter - 1]);
        }
        arr[++iter_arr] = len;
    }
    return (arr);
}

static char    *get_word(const char *str, int start, int len)
{
    char    *new_s;
    int     iter;

    new_s = malloc(sizeof(char) * (len + 1));
    iter = 0;
    while (iter < len)
    {
        new_s[iter] = str[start + iter];
        iter++;
    }
    new_s[iter] = 0;
    return (new_s);
}

char           **csplit(const char *s, char c)
{
    int     wc;
    int     *arr;
    int     iter;
    char    **sub_strs;
    int     iter_sub;

    wc = count_word(s, c, 0);
    arr = get_length_substrings(s, c, wc, 0);
    sub_strs = malloc(sizeof(char *) * (wc + 1));
    iter = 0;
    iter_sub = 0;
    while (s[iter])
    {
        while (s[iter] == c)
            iter++;
        sub_strs[iter_sub] = get_word(s, iter, arr[iter_sub]);
        iter += arr[iter_sub];
        iter_sub++;
    }
    free(arr);
    sub_strs[wc] = NULL;
    return (sub_strs);
}