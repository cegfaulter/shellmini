/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utiils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 23:13:40 by mel-omar          #+#    #+#             */
/*   Updated: 2020/11/13 13:59:41 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"
#include <stdio.h>

static unsigned int    calculate_backslash(const char *str, int idx)
{
    unsigned int count;

    count = 0;
    while (0 <= idx)
    {
        if (str[idx] != '\\')
            break;
        count++;
        idx--;
    }
    return (count);
}

void       check_special(const char *str, int idx, char *special, int *is_back)
{

    if (str[idx] == '\\')
    {
        *is_back = 1;
        return ;
    }
    *is_back = (int)calculate_backslash(str, idx - 1) % 2;
    if (!*is_back && !*special && (str[idx] == '\'' || str[idx] == '"'))
        *special = str[idx];
    else if (!*is_back && *special == str[idx])
        *special = 0;
}


void        free_split(char ***sp)
{
    int     iter;

    iter = 0;
    while ((*sp)[iter])
    {
        free((*sp)[iter]);
        (*sp)[iter] = NULL;
        iter++;
    }
    free(*sp);
    *sp = NULL;
}