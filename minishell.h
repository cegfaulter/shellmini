/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 23:00:20 by settaqi           #+#    #+#             */
/*   Updated: 2020/10/29 10:34:44 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H
# define BUFFER_SIZE 100
# define SIGINT  2
# define SIGQUIT 3

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include <fcntl.h>
# include "GNL/get_next_line.h"
# include "LIBFT/libft.h"
# include "strhandle/command_recognizer/recognizer.h"
# include <errno.h>
# include <string.h>

//ERROR HANDLING
// CHECK ERROR | --> 5
// CHECK ERROR || --> 6
// CHECK ERROR ; --> 8
// CHECK ERROR ;; --> 7

typedef struct			s_minishell
{
	char				*line;
	int					gnl_return;
	char				*currentdirectory;
	char				*home_directory;
	t_list				*list_args;
	char				**path_env;
	short int			error_detected;
	short int			print_shell_line;
	pid_t				current_pid;
}						t_minishell;

typedef struct			s_command
{
	char				**command;
	int					save;
	t_list				*files;
	int					builtins;
}						t_command;

typedef struct			s_files
{
	char				*filename;
	short int			mode; // 0 input - 1 write override - 2 write append
	int					fd;
}						t_files;

typedef struct			s_files_
{
	char				*filename;
	int					fd;
}						t_files_;

t_minishell				g_data;
t_cmap					*g_map_env;

void					ft_commands_line(void);
void					ft_free_split(char **data);
void					ft_set_envp(void);
void					ft_add_envp(char *key, char *value);
void					ft_delete_envp(char *key);
int						ft_update_envp(char *key, char *value);
void					ft_set_env_oldpwd(void);
void					ft_update_env_pwd(void);
void					ft_init_data(int argc, char **argv, char **envp);
void					ft_oldargsvalues(void);
void					ft_echo(char *str, int i, int argc);
void					ft_checkpipeandredirect(void);
void					ft_print_multipiperesult(void);
void					ft_handle_command_args(char **command, int *builtins);
char					*ft_get_env(char *key);
void					ft_echo_builtins(t_command *item, int c);
void					ft_runrightcmd(t_command *item, int c);
void					ft_changedirectory(t_command *item, int c);
void					update_env_global_variable(void);
char					*ft_join_char_str(char *str, char ch);
char					**update_print_env(int c);




void					ft_pwd(int c);




char					*ft_getabsolute_path(char *command, int *builtins);
int						ft_strcmp(char *s1, char *s2);
void					ft_unset(t_command *item, int c);
void					ft_export(t_command *item, int c);
void					ft_exit(t_command *item, int c);
char					*ft_getcurrentdirectory(void);
void					free_globals(void);

void					ft_print_error(void);
int						ft_split_length(char **data_splitted);
void					ft_data_list(t_list **list);
void					print_shell_line(void);
int						ft_max(char *str1, char *str2);
void					print_map(int t);
void					print_env(char **env_2d);
void					ft_signal(void);

#endif
