/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:04:43 by settaqi           #+#    #+#             */
/*   Updated: 2020/01/25 21:31:46 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char		*ft_substr_gnl(char const *s, unsigned int start, int len)
{
	char	*str;
	char	*substring;
	int		i;

	if (!s)
		return (0);
	if (ft_strlen_gnl(s) < start)
		len = 0;
	str = (char*)s;
	if (!(substring = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (len)
	{
		if (str[start] != '\n')
			substring[i++] = str[start++];
		else
			substring[i] = '\0';
		len--;
	}
	substring[i] = '\0';
	return (substring);
}

char			*get_line(char **data, int *v)
{
	char	*line;
	char	*savedata;
	int		c;

	line = 0;
	if (*data != 0)
	{
		savedata = *data;
		c = ft_strchr_gnl(*data, '\n', 0);
		if (!(line = ft_substr_gnl(*data, 0, c)))
		{
			*v = -1;
			return (0);
		}
		if (c == (int)ft_strlen_gnl(line))
			*v = 1;
		if (!(*data = ft_strjoin_gnl("", *data + c)))
		{
			*v = -1;
			return (0);
		}
		free(savedata);
	}
	return (line);
}

int		ft_strchr_gnl(const char *str, int c, int cas)
{
	int		i;

	i = 0;
	if (cas == 2)
	{
		while (*str++)
			if (*(str - 1) == c)
				return (1);
		return (0);
	}
	while (*str)
	{
		i++;
		if (*str == c)
			return (i);
		str++;
	}
	return (i);
}

int				ft_walo(int fd, char **data)
{
	char	*newread;
	size_t	lengthnr;
	char	*savedata;

	newread = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1);
	while ((lengthnr = read(fd, newread, BUFFER_SIZE)) > 0
			&& lengthnr <= BUFFER_SIZE)
	{
		newread[lengthnr] = '\0';
		savedata = *data;
		if (*data == 0)
			*data = ft_strjoin_gnl("", newread);
		else
			*data = ft_strjoin_gnl(*data, newread);
		free(savedata);
		if (ft_strchr_gnl(newread, '\n', 2))
			break ;	
	}
	free(newread);
	return (lengthnr);
}
