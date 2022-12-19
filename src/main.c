/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:52:25 by hrothery          #+#    #+#             */
/*   Updated: 2022/05/20 09:13:36 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_last_exit;

void	lex_parse_execute(char *line, t_envvar *env_list, t_envvar *export_list)
{
	t_list		*lexer_tokens;
	t_command	*cmd_struct;
	t_pdata		p_data;

	if (is_only_whitespaces(line))
		return ;
	p_data.envlist = env_list;
	lexer_tokens = lexer(line);
	if (!lexer_tokens)
		return ;
	cmd_struct = parser(lexer_tokens, env_list);
	if (cmd_struct && !cmd_struct->next && is_builtin(cmd_struct->cmd))
		parse_builtin(cmd_struct, env_list, export_list);
	else if (cmd_struct && cmd_struct->cmd[0])
	{
		p_data.start = cmd_struct;
		p_data.paths = find_paths(env_list);
		pipe (p_data.oldpipe);
		pipex(p_data, env_list, export_list, cmd_struct);
		free_my_paths(p_data.paths);
	}
	free_complete_struct(cmd_struct);
	free_tokens(lexer_tokens);
}

static bool	check_args(int argc, char **argv)
{
	if (argc != 1 || argv[1])
	{
		printf("Run program with ./minishell (no arguments)\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_envvar	*env_list;
	t_envvar	*export_list;

	g_last_exit = 0;
	if (check_args(argc, argv))
		return (0);
	add_history("");
	signal(SIGINT, sighandler);
	signal(SIGQUIT, SIG_IGN);
	env_list = init_envp_list(envp);
	export_list = duplicate_list(env_list);
	while (1)
	{
		line = readline(PROMPT);
		if (!line)
			break ;
		add_history(line);
		lex_parse_execute(line, env_list, export_list);
		free(line);
	}
	free_everything(env_list, export_list, NULL);
	printf("\n");
	return (0);
}
