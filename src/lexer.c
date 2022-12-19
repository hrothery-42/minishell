/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:15:16 by cfabian           #+#    #+#             */
/*   Updated: 2022/05/19 12:56:00 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static size_t	token_length(char *str)
{
	size_t			len;
	const size_t	max_len = ft_strlen(str);

	len = 0;
	while (str[len] == ' ')
		len++;
	if (str[len] == '|' || (str[len] == '<' && str[len + 1] != '<') || \
	(str[len] == '>' && str[len + 1] != '>'))
		return (len + 1);
	if ((str[len] == '<' && str[len + 1] == '<') || \
	(str[len] == '>' && str[len + 1] == '>'))
		return (len + 2);
	while (len < max_len && str[len] != 0 && str[len] != ' ' && \
	str[len] != '|' && str[len] != '<' && str[len] != '>')
	{
		if (str[len] == 39 || str[len] == '"')
			len += ft_strlen_c((str + len + 1), str[len]) + 1;
		len++;
	}
	return (len);
}

char	*tok_err(t_list *tokens)
{
	char	last_tok;
	char	new_tok;

	if (ft_strcmp("|", tokens->content) == 0)
		return (tokens->content);
	last_tok = 's';
	if (is_rdr(tokens->content))
		last_tok = 'r';
	while (tokens->next)
	{
		tokens = tokens->next;
		new_tok = 's';
		if (is_rdr(tokens->content))
			new_tok = 'r';
		else if (ft_strcmp("|", tokens->content) == 0)
			new_tok = 'p';
		if (new_tok == 'p' && last_tok == 'p')
			return (tokens->content);
		if (last_tok == 'r' && new_tok != 's')
			return (tokens->content);
		last_tok = new_tok;
	}
	if (last_tok != 's')
		return (tokens->content);
	return (NULL);
}

void	print_token_error(t_list *st)
{
	print_error("syntax error near unexpected token '", tok_err(st), \
	"'\n", NULL);
	g_last_exit = 258;
}

t_list	*lexer(char *line)
{
	t_list			*st;
	const size_t	len = ft_strlen(line);
	t_tok			token;

	token.start = 0;
	st = NULL;
	while (token.start < len && !is_only_whitespaces(line + token.start))
	{
		token.len = token_length((line + token.start));
		token.string = ft_substr_strip_space(line, token.start, token.len);
		token.start = token.start + token.len;
		if (ft_strlen(token.string) == 0)
			break ;
		if (!st)
			st = ft_lstnew(token.string);
		else
			ft_lstadd_back(&st, ft_lstnew(token.string));
	}
	if (tok_err(st))
	{
		print_token_error(st);
		ft_lstclear(&st);
		return (NULL);
	}
	return (st);
}

/* int	main(void)
{
	char	line[200] = "echo 1234567890 | grep 1 | grep 2 | grep 3 | grep 4 | \
	grep 5 | grep 6 | grep 7 | grep 8 | grep 9 | grep 0 | grep 1 | grep 2 ";
	t_list	*start;
	t_command *start_c;

	g_last_exit = 0;
	start = lexer(line);
	start_c = parser(start);
	printf("%s\n", line);
	while (start_c)
	{
		printf("commands: %s %s, fd_in: %d, fd_out: %d \n", start_c->cmd[0], \
		start_c->cmd[1], start_c->fd_in, start_c->fd_out);
		start_c = start_c->next;
	}
	return (1);
}
*/