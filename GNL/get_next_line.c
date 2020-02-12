/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:04:33 by settaqi           #+#    #+#             */
/*   Updated: 2020/01/25 21:26:17 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t				ft_strlen_gnl(const char *str)
{
	char	*string;
	int		i;

	string = (char*)str;
	i = 0;
	while (*string++ != '\0')
		i++;
	return (i);
}

int					returnvalue(char **tvg, char *data, int v)
{
	if (*tvg == NULL && v == -1)
	{
		return (-1);
	}
	if (data == NULL && *tvg == NULL)
	{
		*tvg = ft_strjoin_gnl("", "");
		return (0);
	}
	if (v == 1)
		return (0);
	return (1);
}

char				*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*string;
	char	*savestr;

	if (!s1 || !s2)
		return (0);
	if (!(string = (char*)malloc((ft_strlen_gnl((char*)s1) +
				ft_strlen_gnl((char*)s2) + 1) * sizeof(char))))
		return (0);
	savestr = string;
	while (*s1)
		*string++ = *s1++;
	while (*s2)
		*string++ = *s2++;
	*string = '\0';
	return (savestr);
}

int					get_next_line(int fd, char **tvg)
{
	static char		*data;
	int				i;
	int				v;

	if (fd < 0 || tvg == NULL || BUFFER_SIZE == 0)
		return (-1);
	v = 0;
	i = ft_walo(fd, &data);
	if (i == -1)
		return (-1);
	*tvg = get_line(&data, &v);
	if (v == 1)
	{
		free(data);
		data = NULL;
	}
	return (returnvalue(tvg, data, v));
}
