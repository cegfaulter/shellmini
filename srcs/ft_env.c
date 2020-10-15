/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:10:49 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/14 10:56:09 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			ft_arr_length(char **data)
{
	int		i;

	i = 0;
	while (data[i])
		i++;
	return (i);
}

void		ft_set_envp(void)
{
	int			i;
	char		**data_splitted;
	t_keyval	*newvar;

	i = 0;
	while (g_data.envp[i])
	{
		data_splitted = ft_split(g_data.envp[i], '=');
		newvar = (t_keyval*)(malloc(sizeof(t_keyval) * 1));
		newvar->key = ft_strdup(data_splitted[0]);
		newvar->value = ft_strdup(ft_arr_length(data_splitted)
						> 1 ? data_splitted[1] : "");
		ft_lstadd_back(&(g_data.list_envp), ft_lstnew(newvar));
		i++;
	}
}

void		ft_add_envp(char *key, char *value)
{
	t_keyval	*newvar;

	newvar = (t_keyval*)(malloc(sizeof(t_keyval) * 1));
	newvar->key = ft_strdup(key);
	newvar->value = ft_strdup(value);
	ft_lstadd_back(&(g_data.list_envp), ft_lstnew(newvar));
}

void		ft_delete_envp(char *key)
{
	t_list		*list_tmp;
	t_keyval	*updated_var;
	t_list		*tmp_node;

	if (key == NULL)
		return ;
	list_tmp = g_data.list_envp;
	while (list_tmp)
	{
		if (list_tmp->next != NULL)
			if (ft_strncmp(key, (char*)((t_keyval*)
			list_tmp->next->content)->key, ft_strlen(key)) == 0)
			{
				free((char*)((t_keyval*)
				list_tmp->next->content)->key);
				free((char*)((t_keyval*)
				list_tmp->next->content)->value);
				free((t_keyval*)list_tmp->next->content);
				tmp_node = list_tmp->next;
				list_tmp->next = list_tmp->next->next;
				free(tmp_node);
			}
		list_tmp = list_tmp->next;
	}
}

int				ft_update_envp(char *key, char *value)
{
	t_list		*list_tmp;
	t_keyval	*updated_var;

	if (key == NULL)
		return (-1);
	list_tmp = g_data.list_envp;
	while (list_tmp)
	{
		if (ft_strncmp(key, (char*)((t_keyval*)
			list_tmp->content)->key, ft_strlen(key)) == 0)
		{
			updated_var = (t_keyval*)(malloc(sizeof(t_keyval) * 1));
			updated_var->key = ft_strdup(key);
			updated_var->value = ft_strdup(value);
			free((char*)((t_keyval*)list_tmp->content)->value);
			free((char*)((t_keyval*)list_tmp->content)->key);
			free((t_keyval*)list_tmp->content);
			list_tmp->content = updated_var;
			return (1);
		}
		list_tmp = list_tmp->next;
	}
	if (list_tmp == NULL)
		return (0);
	return (-1);
}

char		*ft_get_env(char *key)
{
	t_list		*list_tmp;

	list_tmp = g_data.list_envp;
	while (list_tmp)
	{
		if (list_tmp->next != NULL)
			if (ft_strncmp(key, (char*)((t_keyval*)
			list_tmp->content)->key, ft_strlen(key)) == 0)
				return ((char*)((t_keyval*)list_tmp->content)->value);
		list_tmp = list_tmp->next;
	}
	return (ft_strdup(""));
}

void		update_env_global_variable(void)
{
	t_list		*tmp_list;
	int			length_list;
	char		**new_envp;
	int			i;

	tmp_list = g_data.list_envp;
	length_list = ft_lstsize(tmp_list);
	new_envp = (char**)malloc(sizeof(char*) * length_list + 1);
	i = 0;
	while (tmp_list)
	{
		new_envp[i] = ft_join_char_str(((t_keyval*)
			tmp_list->content)->key, '=');
		new_envp[i] = ft_strjoin(new_envp[i],
			((t_keyval*)tmp_list->content)->value);
		i++;
		tmp_list = tmp_list->next;
	}
	new_envp[i] = 0;
	g_data.updated_env = new_envp;
}

void		update_print_env(int c)
{
	int		i;
	char	**env_2d;

	i = 0;
	env_2d = from_map_to_arr(g_map_env);
	while (env_2d[i])
		printf("%s\n", env_2d[i++]);
}
