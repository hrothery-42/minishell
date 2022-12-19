/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 08:42:52 by cfabian           #+#    #+#             */
/*   Updated: 2022/05/18 12:41:30 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	dup2_and_close(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
		perror("What the hell- how did you manage to give dup2 an error?");
	close(oldfd);
}

static void	parent_process(t_pdata pdata, t_command *cmd_s)
{
	signal(SIGINT, SIG_IGN);
	close(pdata.oldpipe[0]);
	close(pdata.oldpipe[1]);
	dup2_and_close(pdata.newpipe[0], pdata.oldpipe[0]);
	dup2_and_close(pdata.newpipe[1], pdata.oldpipe[1]);
	if (!cmd_s->next)
	{
		while (true)
		{
			if (wait (&g_last_exit) <= 0)
			{
				signal(SIGINT, sighandler);
				break ;
			}
		}
	}
	g_last_exit = g_last_exit / 255;
}

static void	prepare_pipes(t_pdata pd, t_command *cmd_s)
{
	if (!(pd.start == cmd_s))
		dup2_and_close(pd.oldpipe[0], STDIN_FILENO);
	if (cmd_s->fd_in != 0)
		dup2_and_close(cmd_s->fd_in, STDIN_FILENO);
	if (!cmd_s->next || cmd_s->fd_out != 1)
		dup2_and_close(cmd_s->fd_out, pd.newpipe[1]);
	dup2_and_close(pd.newpipe[1], STDOUT_FILENO);
	close(pd.newpipe[0]);
	close(pd.oldpipe[1]);
}

void	child_p(t_pdata pd, t_envvar *env_l, t_envvar *exp_l, t_command *cmd_s)
{
	char	*path;
	char	**own_env;

	if (cmd_s->fd_in != -1 && cmd_s->fd_out != -1)
	{
		path = NULL;
		prepare_pipes(pd, cmd_s);
		if (is_builtin(cmd_s->cmd))
			parse_builtin(cmd_s, env_l, exp_l);
		else if (cmd_s->cmd && cmd_s->cmd[0])
		{
			own_env = ft_listtostr(env_l);
			execve(cmd_s->cmd[0], cmd_s->cmd, own_env);
			path = joined_path(pd.paths, cmd_s->cmd[0]);
			if (path)
				execve(path, cmd_s->cmd, own_env);
			free(path);
			ft_double_free(own_env);
			print_error(cmd_s->cmd[0], ": command not found\n", NULL, NULL);
		}
	}
	free_everything(env_l, exp_l, pd.start);
	exit(127);
}

int	pipex(t_pdata pd, t_envvar *env_lst, t_envvar *exp_lst, t_command *cmd_s)
{
	if (!cmd_s)
	{
		close(pd.oldpipe[0]);
		close(pd.oldpipe[1]);
		return (0);
	}
	if (pipe(pd.newpipe) < 0)
		perror("pipe");
	pd.pid = fork();
	if (pd.pid < 0)
		perror("Fork");
	else if (pd.pid != 0)
	{
		parent_process(pd, cmd_s);
		pipex(pd, env_lst, exp_lst, cmd_s->next);
	}
	else
	{
		signal(SIGINT, sighandler_child);
		child_p(pd, env_lst, exp_lst, cmd_s);
	}
	return (0);
}
