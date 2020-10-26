

#include "recognizer.h"
#include <string.h>
#include "../../minishell.h"

void	remove_value(t_clist **lst, char *key)
{
	t_clist		*temp;
	t_clist		*before;

	if (!*lst)
		return ;
	if (!strcmp((*lst)->data, key))
	{
		before = *lst;
		*lst = (*lst)->next;
		free(before);
	}
	else
	{
		before = *lst;
		temp = (*lst)->next;
		while (temp)
		{
			if (!strcmp(temp->data, key))
			{
				before->next = temp->next;
				free(temp);
				break ;
			}
			before = temp;
			temp = temp->next;
		}
	}
}

char			*get_lowest(t_clist *lst)
{
	char		*lowest;

	lowest = NULL;
	while (lst)
	{
		if (!lowest || strcmp(lowest, lst->data) > 0)
			lowest = (char *)lst->data;
		lst = lst->next;
	}
	return (lowest);
}

t_clist			*sorted_keys(t_clist **to_sort)
{
	char		*lowest;
	t_clist		*sorted;

	sorted = NULL;
	while (*to_sort)
	{
		lowest = get_lowest(*to_sort);
		append(&sorted, ft_cstrdup(lowest));
		remove_value(to_sort, lowest);
	}
	return (sorted);
}

int		check_reserved_key(char *key)
{
	int		i;

	i = 0;
	while (g_reserved[i])
	{
		if (ft_strcmp(key, g_reserved[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

char			**from_map_to_arr(t_cmap *map, int c)
{
	t_clist		*keys;
	char		**arr;
	t_clist		*key;
	int			iter;
	char		*tmp;

	g_reserved = ft_split("? 1 2 3 4 5 6 7 8 9", ' ');
	keys = get_keys(map);
	if (!(arr = malloc(sizeof(char *) * (length(keys) + 1))))
		return (NULL);
	keys = sorted_keys(&keys);
	key = keys;
	iter = 0;
	while (key)
	{
		if (check_reserved_key(key->data))
		{
			if (c == 1)
			{
				arr[iter] = ft_cstrjoin(ft_cstrdup(key->data), ft_cstrdup("="));
				arr[iter] = ft_cstrjoin(arr[iter], ft_cstrdup(get(map, key->data)));
			}
			else if (c == 2)
			{
				tmp = get(g_map_env, key->data);
				if (ft_strlen(tmp) <= 0)
					print("declare -x %s\n", key->data, get(g_map_env, key->data));
				else
					print("declare -x %s=\"%s\"\n", key->data, get(g_map_env, key->data));
				free(tmp);
			}
			iter++;
		}
		key = key->next;
	}
	arr[iter] = NULL;
	clear_list(&keys, free);
	free_split(&g_reserved);
	return (arr);
}
