/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_rec2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:29:02 by mel-omar          #+#    #+#             */
/*   Updated: 2020/03/11 09:24:51 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"
/*
int         main(int argc, char **argv, char **var_env)
{
    char        **sp;
    char        *s;
    int         iter;
    t_clist     *lst = NULL;
    t_clist     *all = NULL;
    t_ccommand  *hi;

    iter = 0;
    while (1)
    {
        print(">>> ");
        get_next_line(1, &s);
        //s = "< file echo";
        all = all_commands(s, var_env);
        while (all)
        {
            print(">> %d\n", iter);
            hi = (t_ccommand *)all->data;
            while (hi->keys)
            {
                print("%s\n", (char *)hi->keys->data);
                print_rec(get_cmd(hi->full_command, (char *)hi->keys->data));
                hi->keys = hi->keys->next;
            }
            all = all->next;
            iter++;
            print("\n\n");
        }
        free_all_commands(&lst);
        free(s);
    }
    return (0);
}
*/
