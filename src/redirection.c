/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:41:26 by cfabian           #+#    #+#             */
/*   Updated: 2022/05/17 19:00:02 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_rdr(char *token_string)
{
	if (ft_strcmp(">", token_string) == 0)
		return (OUTPUT_TRUNC);
	if (ft_strcmp("<", token_string) == 0)
		return (INPUT);
	if (ft_strcmp(">>", token_string) == 0)
		return (OUTPUT_APP);
	if (ft_strcmp("<<", token_string) == 0)
		return (HEREDOC);
	return (0);
}

bool	output_redirection(t_command *cmd, t_list *token, int tr_or_app)
{
	if (cmd->fd_out > 1)
		close(cmd->fd_out);
	cmd->fd_out = open(token->content, O_CREAT | tr_or_app | O_RDWR, 0666);
	return (0);
}

static bool	check_redi_error(int type, t_command *cmd, char *str)
{
	if ((type <= 2 && cmd->fd_in == -1) || (type >= 3 && cmd->fd_out == -1))
	{
		perror(str);
		return (0);
	}
	return (1);
}

int	rdr(t_command *cmd, t_list *token, int type, t_envvar *env_list)
{
	int	error;

	if (type == OUTPUT_TRUNC)
		output_redirection(cmd, token, O_TRUNC);
	else if (type == OUTPUT_APP)
		output_redirection(cmd, token, O_APPEND);
	else if (type == INPUT)
	{
		if (cmd->fd_in > 0)
			close(cmd->fd_in);
		cmd->fd_in = open(token->content, O_RDONLY);
	}
	else if (type == HEREDOC)
	{
		exe_heredoc(token->content, env_list);
		if (cmd->fd_in > 0)
			close(cmd->fd_in);
		cmd->fd_in = open(".tmpheredoc", O_RDONLY);
		unlink(".tmpheredoc");
	}
	error = check_redi_error(type, cmd, token->content);
	return (error);
}
