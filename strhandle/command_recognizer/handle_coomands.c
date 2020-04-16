/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_coomands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 07:10:13 by mel-omar          #+#    #+#             */
/*   Updated: 2020/03/12 13:53:52 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

char        *single_double_quotes(char *str, int *iter, char c, t_cmap *map)
{
    char    *ret;

    (*iter)++;
    if (c == '"')
        ret = (double_quotes(str, iter, map));
    else
        ret = (single_quotes(str, iter));
    (*iter)++;
    return (ret);
}


char        *get_command(char *str, int *iter, t_cmap *map)
{
    char       *s;

    s = NULL;
    while (str[*iter] == ' ')
        (*iter)++;
    while (str[*iter] && !in_set(str[*iter]," ><"))
    {
        if (str[*iter] == '\'' || str[*iter] == '"')
            s = ft_cstrjoin(s, single_double_quotes(str, iter, str[*iter], map));
        else
            s = ft_cstrjoin(s, withback(str, map, iter));
    }
    return (s);
}

void    copy(t_clist **a, t_clist *b)
{
    while (b)
    {
        append(a, ft_cstrdup((char *)b->data));
        b = b->next;
    }
}
t_rec       *join_rec(t_rec *rec1, t_rec *rec2)
{
    t_rec   *rec;

    rec = init_rec();
    if (rec1)
    {
        copy(&rec->files, rec1->files);
        copy(&rec->text, rec1->text);
        copy(&rec->oper, rec1->oper);
    }
    if (rec2)
    {
        copy(&rec->files, rec2->files);
        copy(&rec->text, rec2->text);
        copy(&rec->oper, rec2->oper);
    }
    free_rec(&rec1);
    free_rec(&rec2);
    return  (rec);
}

t_rec       *handle_command(char *str, t_cmap *map, int *iter, int is_found)
{
    int         is_file;
    t_rec       *rec;
    char        *cmd;
    char        *s;

    is_file = 0;
    rec = init_rec();
    s = NULL;
    while (str[*iter])
    {
       if (str[*iter] == '>' || str[*iter] == '<')
       {
           get_oper(str, iter, &rec->oper);
           is_file = 1;
       }
       else if (str[*iter] == ' ')
            while (str[++(*iter)] == ' ');
        else if (is_file)
        {
            enter(str, iter, map,&rec->files);
            is_file = 0;
        }
        else
            enter(str, iter, map, &rec->text);
    }
    return (rec);
}

void       add_command(char *cmd, t_cmap *mp, t_cmap *global_vars, t_clist **lst)
{
    char    *key;
    t_rec   *value;
    int     i;
    int     is_found;

    value = NULL;
    is_found = 0;
    i = 0;
    while (cmd[i] == ' ')
        i++;
    while (!is_found)
    {
        if (!in_set(cmd[i], "><"))
        {
            key =  get_command(cmd, &i, global_vars);
            is_found = 1;
        }
        value = join_rec(value, handle_command(cmd, global_vars, &i, is_found));
    }
    set_cmd(mp, key, value);
    append(lst, key);
}

t_cmap      *get_command_line(char *cmd, t_cmap *global_vars, t_clist **lst)
{
    t_cmap      *all_cmds;
    char        **commands;
    int         iter;

    all_cmds = init_map();
    commands = csplit(cmd,'|');
    iter = 0;
    while (commands[iter])
    {
        add_command(commands[iter], all_cmds, global_vars, lst);
        iter++;
    }
    free_split(&commands);
    return (all_cmds);
}