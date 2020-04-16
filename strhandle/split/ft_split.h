/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:57:03 by mel-omar          #+#    #+#             */
/*   Updated: 2020/03/09 03:28:31 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_H
# define FT_SPLIT_H

# include <stdlib.h>

void		set(char *to_split, char c, char *ignored, char sp);
char		**ft_csplit(char *s, char c, char *ignored);
#endif
