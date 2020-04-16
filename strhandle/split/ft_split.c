/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:33:02 by mel-omar          #+#    #+#             */
/*   Updated: 2020/03/09 02:33:48 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

static int			words(char *s, char c, char *n)
{
	char		to_split;
	int			count;
	int			iter;
	int			locked;

	locked = 1;
	iter = -1;
	count = 0;
	to_split = 0;
	while (s[++iter])
	{
		set(&to_split, s[iter], n, c);
		if ((!to_split && s[iter] == c))
			locked = 1;
		if (locked)
		{
			count++;
			locked = 0;
		}
	}
	return (count);
}

static int			count_length(char *s, char c, char *n, int *start)
{
	int		iter;
	char	to_split;

	iter = 0;
	to_split = 0;
	while (s[iter + *start])
	{
		set(&to_split, s[iter + *start], n, c);
		if (!to_split && s[iter + *start] == c)
			break ;
		iter++;
	}
	*start += iter;
	return (iter);
}

static int			*count_length_words(char *s, char c, char *n)
{
	int		start;
	int		iter;
	int		word_count;
	int		*length;

	start = 0;
	iter = 0;
	word_count = words(s, c, n);
	length = malloc(sizeof(int) * (word_count));
	while (iter < word_count)
	{
		while (s[start] == c)
			start++;
		length[iter] = count_length(s, c, n, &start);
		iter++;
	}
	return (length);
}

static int			copystr(char *dst, char *src, int start, int len)
{
	int		iter;

	iter = 0;
	while (iter < len)
	{
		dst[iter] = src[start + iter];
		iter++;
	}
	dst[len] = 0;
	return (len);
}

char				**ft_csplit(char *s, char c, char *ignored)
{
	char		**spliter;
	int			count_words;
	int			*lengths;
	int			iter;
	int			start;

	iter = -1;
	count_words = words(s, c, ignored);
	spliter = (char **)malloc(sizeof(char *) * (count_words + 1));
	spliter[count_words] = NULL;
	lengths = count_length_words(s, c, ignored);
	start = 0;
	while (++iter < count_words)
	{
		while (s[start] == c)
			start++;
		spliter[iter] = (char *)malloc(sizeof(char) * (lengths[iter] + 1));
		start += copystr(spliter[iter], s, start, lengths[iter]);
	}
	free(lengths);
	return (spliter);
}
