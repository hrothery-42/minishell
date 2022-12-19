/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:37:21 by cfabian           #+#    #+#             */
/*   Updated: 2022/05/20 10:01:30 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAX_ENVVAR_LEN 128
# define MAX_TOKEN_LEN 1256
# define MAX_PWD 128
# define PROMPT "\033[1;36m\033[1mMinishell\033[0m$ "
# define GRN  "\x1B[1;32m"
# define BLU  "\x1B[1;34m"
# define NRM  "\x1B[0m"
# define BUFFER_SIZE 40
# define INPUT 1
# define HEREDOC 2
# define OUTPUT_TRUNC 3
# define OUTPUT_APP 4
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include "./libft.h"
# include <stdbool.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

extern int	g_last_exit;

typedef struct s_envvar
{
	char			*name;
	char			*content;
	struct s_envvar	*next;
}	t_envvar;

typedef struct s_quotes_and_envvars
{
	size_t		i;
	size_t		j;
	char		*buf;
	size_t		end;
	bool		quote[2];
	t_envvar	*env_list;
}	t_quotes_and_envvars;

typedef struct s_tok
{
	size_t	start;
	size_t	len;
	char	*string;
}	t_tok;

typedef struct s_command
{
	int					fd_in;
	int					fd_out;
	int					ct;
	char				**cmd;
	struct s_command	*next;
}	t_command;

typedef struct s_pdata
{
	int			newpipe[2];
	int			oldpipe[2];
	char		**paths;
	char		*c_p;
	bool		first_cmd;
	pid_t		pid;
	t_command	*start;
	t_envvar	*envlist;
}	t_pdata;

//builtin_parser.c
int			builtin_echo(char **cmd, int fd_out);
int			parse_builtin(t_command *cmd_str, t_envvar *env_list, \
			t_envvar *exp_list);

//builtin_utils.c
char		*ft_get_envvar(t_envvar *env_list, char *s);
int			is_alpha_numeric_underscore(char *s);
void		add_export_envvar(t_envvar *lst, char *s);
void		add_envvar(t_envvar *lst, char *s);

//builtins.c
int			builtin_env(char **cmd_struct, int fd, t_envvar *list);
int			builtin_pwd(int fd);
int			builtin_cd(char **cmd, t_envvar *env_list);
int			builtin_exit(t_command *cmd_struct, t_envvar *env_lst, \
			t_envvar *exp_list);

//env_list.c
t_envvar	*new_var(t_envvar *lst);
t_envvar	*init_envp_list(char **envp);
t_envvar	*init_var(t_envvar *var, char *envp);
int			search_env_list(t_envvar *lst, char *cmd);

//error_msg.c
void		print_error(char *str1, char *str2, char *str3, char *str4);

//exec_utils
void		free_my_paths(char **paths);
char		**find_paths(t_envvar *env_list);
char		*joined_path(char **my_paths, char *token);

//export_list.c
t_envvar	*init_export_var(t_envvar *var, char *envp);
int			search_exp_list(t_envvar *lst, char *cmd);

//export.c
t_envvar	*export_new_var(t_envvar *lst, t_envvar *new);
void		print_export_no_args(t_envvar *export_list, int fd);
int			builtin_export(t_envvar *env_list, t_envvar *exp_list, \
			char **cmd, int fd);

//free.c
void		free_var_list(t_envvar *lst);
void		free_tokens(t_list *tokens);
void		free_cmd_struct(t_command *temp);
void		free_everything(t_envvar *env, t_envvar *exp, t_command *cmd_s);
void		free_complete_struct(t_command *cmd_struct);

//get_next_line_delimit
char		*gnl_delimit(int fd, char *delimiter);

//heredoc.c
void		exe_heredoc(char *delimiter, t_envvar *env_list);

//init_export_list.c
t_envvar	*add_var_to_list(t_envvar *lst, t_envvar *new);
t_envvar	*duplicate_variable(t_envvar *lst, t_envvar *new);
t_envvar	*create_first_export_var(t_envvar *exp_list);
t_envvar	*duplicate_list(t_envvar *lst);

//lexer.c
char		*tok_err(t_list *tokens);
void		print_token_error(t_list *st);
t_list		*lexer(char *line);

//list_to_string.c
char		**ft_listtostr(t_envvar *env_list);
void		ft_double_free(char **s);

//parser.c
t_command	*look_for_builtin(t_command *cmd_first, t_command *cmd);
t_command	*parser(t_list *token, t_envvar *env_list);
bool		is_builtin(char **cmd);

//piping.c
int			pipex(t_pdata pdata, t_envvar *env_list, \
			t_envvar *exp_list, t_command *cmd_struct);

//quotes and envars
char		*quotes_and_envvars(char *string, size_t len, t_envvar *env_list);

//redirection.c
int			is_rdr(char *token_string);
int			rdr(t_command *cmd, t_list *token, int type, t_envvar *env_list);

//signals.c
void		sighandler(int num);
void		sighandler_child(int num);

//unset.c
void		del_var(t_envvar *lst, int first);
void		search_variable_to_delete(t_envvar *lst, char *s);
int			builtin_unset(t_envvar *env_list, t_envvar *exp_list, char **cmd);

#endif
