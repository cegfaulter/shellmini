/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utiils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 23:13:40 by mel-omar          #+#    #+#             */
/*   Updated: 2020/03/11 10:53:25 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

void       check_special(char c, char *special, int *is_back, char sp)
{
    if (*is_back)
        *is_back = 0;
    else if (!*is_back && sp == '\\')
        *is_back = 1;
    if (!*special && (c == '\'' || c == '"'))
        *special = c;
    else if ((c == '\'' || c == '"') && *special == c)
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