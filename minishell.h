/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 23:00:20 by settaqi           #+#    #+#             */
/*   Updated: 2020/02/12 18:10:20 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H
# define BUFFER_SIZE 100

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include <fcntl.h>
# include "GNL/get_next_line.h"
# include "LIBFT/libft.h"
# include "strhandle/command_recognizer/recognizer.h"

typedef struct	s_minishell
{
	char		*line;
	int			gnl_return;
	char		*currentdirectory;
	char		**envp;
	int			argc;
	char		**argv;
	t_list		*list_envp;
	char		*home_directory;
	t_list		*list_args;
	char		**path_env;
	char		**updated_env;
}				t_minishell;

typedef struct	s_keyval
{
	char		*key;
	char		*value;
}				t_keyval;

typedef struct	s_command_attr
{
	char		*prog_name;
	t_list		*list_args;
}				t_command_attr;

typedef struct	s_command
{
	char		**command;
	int			saveit;
	char		*filename;
	int			mode;
	char		*inputfilename;
	int			inputfile;
	int			builtins;
	short int	errodetected;
}				t_command;

typedef struct	s_dirent {
	ino_t			d_ino;
	off_t			d_off;
	unsigned short	d_reclen;
	unsigned char	d_type;
	char			d_name[256];
}				t_dirent;

t_minishell		g_data;
t_command_attr	g_args;

void			ft_commands_line(void);
void			ft_free_split(char ***data);
void			ft_set_envp(void);
void			ft_add_envp(char *key, char *value);
void			ft_delete_envp(char *key);
int				ft_update_envp(char *key, char *value);
void			ft_set_env_oldpwd(void);
void			ft_update_env_pwd(void);
void			ft_init_data(int argc, char **argv, char **envp);
void			ft_oldargsvalues(void);
void			ft_echo(char *str, int i, int argc);
void			ft_checkpipeandredirect(void);
void			ft_print_multipiperesult(void);
void			ft_handle_command_args(char **command, int *builtins);
char			*ft_get_env(char *key);
void			ft_echo_builtins(t_command *item, int c);
void			ft_runrightcmd(t_command *item, int c);
void			ft_changedirectory(t_command *item, int c);
void			update_env_global_variable(void);
char			*ft_join_char_str(char *str, char ch);
void			update_print_env(int c);
void			ft_pwd(int c);

#endif
