/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:35:57 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/12 16:25:03 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECOGNIZER_H
# define RECOGNIZER_H

# include "../dt/linkedlist/linkedlist.h"
# include "../dt/hash_table/hash_map.h"
# include "../split/ft_split.h"
# include "../print/print.h"
# include <stdlib.h>

typedef struct	s_rec
{
	char		*text;
	t_clist		*files;
	t_clist		*oper;
}				t_rec;

t_rec			*init_rec();
int				in_set(char c, char *set);
void			switcher(char s, char *ignored);
int				get_operator(t_rec *rec, char *str, int *is_);
int				get_files(t_rec *rec, char *str, char *ignored, int *is_);
int				get_text(t_rec *rec, char *str, char *ignored);
char			*ft_cstrjoin(char *text, char *s);
char			*ft_cstrcpy(char *dst, const char *src, int len);
int				ft_cstrlen(const char *s);
char			*ft_csubstr(char *str, int len);
t_rec			*init_rec();
void			init_condition(int *cond, int size, char *c);
void			display_data(void *data);
void			print_rec(t_rec *rec);
t_cmap			*get_cmd_data(char	*str);
t_rec			*get_cdata(t_cmap *cd, char *key);
void			free_keys(t_clist	**keys);
void			free_cmd_data(t_cmap **cmd_data);
void			free_rec(t_rec **rec);
#endif
