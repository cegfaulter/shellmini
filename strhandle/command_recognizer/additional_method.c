

#include "recognizer.h"
#include <string.h>

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

char        *get_lowest(t_clist *lst)
{
    char        *lowest;

    lowest = NULL;
    while (lst)
    {
        if (!lowest || strcmp(lowest, lst->data) > 0)
            lowest = (char *)lst->data;
        lst = lst->next;
    }
    return (lowest);
}

t_clist     *sorted_keys(t_clist **to_sort)
{
    char        *lowest;
    t_clist     *sorted;

    sorted  = NULL;
    while (*to_sort)
    {
        lowest = get_lowest(*to_sort);
        append(&sorted, ft_cstrdup(lowest));
        remove_value(to_sort, lowest);
    }
    return (sorted);
}

char    **from_map_to_arr(t_cmap *map)
{
    t_clist     *keys;
    char        **arr;
    t_clist     *key;
    int         iter;

    keys = get_keys(map);
    arr = malloc(sizeof(char *) * (length(keys) + 1));
    keys = sorted_keys(&keys);
    key = keys;
    iter = 0;
    while (key)
    {
        arr[iter] = ft_cstrjoin(ft_cstrdup(key->data), ft_cstrdup("="));
        arr[iter] = ft_cstrjoin(arr[iter], ft_cstrdup(get(map, key->data)));
        iter++;
        key = key->next;
    }
    arr[iter] = NULL;
    clear_list(&keys, free);
    return (arr);
}