/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_rec2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:29:02 by mel-omar          #+#    #+#             */
/*   Updated: 2020/04/30 00:15:33 by elomary00        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"
#include <stdio.h>

int         main(int argc, char **argv, char **var_env)
{
    char        **arr2d;
    char        *s;
    int         iter;
    t_cmap      *global_env;
    t_ccommand  *hi;

    iter = 0;
    global_env = put_vars(var_env);

    //add value
    setv(global_env, "hello", ft_cstrdup("elomary"));
    //get value
    printf("%s\n------------\n", get(global_env, "hello"));
    // update value
    setv(global_env, "hello", ft_cstrdup("mohamed elomary"));
    // convert map to sorted arr 2d
    arr2d = from_map_to_arr(global_env);
    // print arr2d
    while (arr2d[iter])
    {
        printf("%s\n", arr2d[iter]);
        iter++;
    }
    // free map and arr2d at end
    clear_map(&global_env, free_vars);
    free_table2d(&arr2d);
    return (0);
}