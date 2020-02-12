/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:17:33 by settaqi           #+#    #+#             */
/*   Updated: 2020/02/12 17:46:14 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		get_st_en(const char *str, char ch, int start, int cas)
{
	int		i;

	i = start;
	if (cas == 0)
	{
		while (str[i] != '\0')
			if (str[i++] != ch)
				return (--i);
		if (str[i] == '\0')
			return (-1);
	}
	i = start;
	if (cas == 1)
	{
		while (str[i] != '\0')
			if (str[i++] == ch)
				return (--i);
		if (str[i] == '\0')
			return (i);
	}
	return (-2);
}

static int		get_words(const char *str, char ch, int cas, int wordnum)
{
	int		i;
	int		start;
	int		end;
	int		words;

	i = 0;
	words = 0;
	end = 0;
	start = 0;
	while (start != -1)
	{
		start = get_st_en(str, ch, end, 0);
		end = get_st_en(str, ch, start, 1);
		if (cas == 1 && (words == wordnum))
			return (start);
		words++;
	}
	return (words - 1);
}

static void		fillthechar(const char *str, char *ptr, int start, int length)
{
	int		i;

	i = 0;
	while (i < length)
		ptr[i++] = str[start++];
	ptr[i] = '\0';
}

char			**ft_split(const char *str, char ch)
{
	int		words;
	int		length;
	int		i;
	char	**splitter;
	int		start;

	if (!str)
		return (0);
	words = get_words(str, ch, 0, 0);
	if (!(splitter = (char**)malloc((words + 1) * sizeof(char*))))
		return (0);
	i = 0;
	length = 0;
	start = 0;
	while (i < words)
	{
		start = get_words(str, ch, 1, i);
		length = get_st_en(str, ch, start, 1) - start;
		if (!(splitter[i] = (char*)malloc((length + 1) * sizeof(char))))
			return (0);
		fillthechar(str, *(splitter + i), start, length);
		i++;
	}
	splitter[i] = 0;
	return (splitter);
}
