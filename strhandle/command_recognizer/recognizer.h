/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:35:57 by mel-omar          #+#    #+#             */
/*   Updated: 2020/03/12 13:26:25 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECOGNIZER_H
# define RECOGNIZER_H

# include "../dt/linkedlist/linkedlist.h"
# include "../dt/hash_table/hash_map.h"
# include "../split/ft_split.h"
# include "../print/print.h"
# include "../gnl/get_next_line.h" 
# include <stdlib.h>

typedef struct	s_rec
{
	t_clist		*text;
	t_clist		*files;
	t_clist		*oper;
}				t_rec;

typedef struct  s_ccommand
{
	char		*cmd;
    t_rec		*data;
}               t_ccommand;

t_rec			*init_rec();
int				in_set(char c, char *set);
char			*ft_cstrjoin(char *text, char *s);
char			*ft_cstrcpy(char *dst, const char *src, int len);
int				ft_cstrlen(const char *s);
char			*ft_csubstr(char *str, int len);
char			*ft_cstrdup(char *str);
void			display_data(void *data);
//split
void			check_special(char c, char *special, int *is_back, char sp);
char			**csplit(const char *s, char separator);
void			free_split(char ***sp);
//endsplit
char            *withback(char *str, t_cmap *map, int *iter);
char            *double_quotes(char *str, int *i, t_cmap *map);
void			print_rec(t_rec *rec);
void			free_keys(t_clist	**keys);
void			free_cmd_data(t_cmap **cmd_data);
void			free_rec(t_rec **rec);
int      		var_len(char *str, int *iter, t_cmap *map);
char			*get(t_cmap *map, const char *key);
void			setv(t_cmap *map, const char *key, char *value);
void			enter(char  *str, int *iter, t_cmap *map, t_clist **lst);
void			get_oper(char *str, int *iter, t_clist **operator);
t_cmap			*put_vars(char **vars);
char			*single_double_quotes(char *str, int *iter, char c, t_cmap *map);
char			*get_command(char *str, int *iter, t_cmap *map);
t_rec       	*handle_command(char *str, t_cmap *map, int *iter, int is_found);
void			add_command(char *cmd, t_clist **lst, t_cmap *global_vars);
t_clist			*get_command_line(char *cmd, t_cmap *global_vars);
t_clist			*all_commands(char *s, char **envs);
int				variables(char *dest, char *str, int *iter, t_cmap *map);
char			*single_quotes(char *str, int *iter);
void			free_ccommand(void *cmd);
void			free_all_commands(t_clist **lst);
void			free_vars(void *vars);
#endif
