/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:30:14 by hrothery          #+#    #+#             */
/*   Updated: 2022/05/12 14:39:46 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	echo_tokens(int *i, int *j, char **cmd, int fd_out)
{
	if (*i != 1 && cmd[*i - 1][0])
		ft_putstr_fd(" ", fd_out);
	ft_putstr_fd(cmd[*i + *j], fd_out);
		(*i)++;
}

static int	is_newline(char *s)
{
	int	i;

	if (s[0] != '-')
		return (0);
	i = 1;
	while (s[i] == 'n')
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

int	builtin_echo(char **cmd, int fd_out)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	g_last_exit = 0;
	if (cmd[i] == NULL)
	{
		ft_putstr_fd("\n", fd_out);
		return (0);
	}
	while (is_newline(cmd[i + j]))
	{
		j++;
		if (cmd[i + j] == NULL)
			return (0);
	}
	while (cmd[i + j] != NULL)
		echo_tokens(&i, &j, cmd, fd_out);
	if (j == 0)
		ft_putstr_fd("\n", fd_out);
	return (0);
}

int	parse_builtin(t_command *cmd_str, t_envvar *env_list, t_envvar *exp_list)
{
	char	**cmd;
	int		fd_out;

	cmd = cmd_str->cmd;
	if (cmd_str->next)
		fd_out = 1;
	else
		fd_out = cmd_str->fd_out;
	if (ft_strcmp(cmd[0], "echo") == 0)
		return (builtin_echo(cmd, fd_out));
	else if (ft_strcmp(cmd[0], "pwd") == 0)
		return (builtin_pwd(fd_out));
	else if (ft_strcmp(cmd[0], "env") == 0)
		return (builtin_env(cmd, fd_out, env_list));
	else if (ft_strcmp(cmd[0], "exit") == 0)
		return (builtin_exit(cmd_str, env_list, exp_list));
	else if (ft_strcmp(cmd[0], "cd") == 0)
		return (builtin_cd(cmd, env_list));
	else if (ft_strcmp(cmd[0], "unset") == 0)
		return (builtin_unset(env_list, exp_list, cmd));
	else if (ft_strcmp(cmd[0], "export") == 0)
		return (builtin_export(env_list, exp_list, cmd, fd_out));
	return (1);
}
