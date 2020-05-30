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

    t_cmap *map = init_map();

    setv(map, "hello", ft_cstrdup("world"));
    setv(map, "makaine maidare", ft_cstrdup("again"));
    //to remove variables popv
    popv(map, "makaine maidare");
    char *value = get(map, "makaine maidare");
    if (value)
        printf("%s\n", value);
    return (0);
}