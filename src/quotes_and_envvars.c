/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_and_envvars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:06:08 by cfabian           #+#    #+#             */
/*   Updated: 2022/05/13 16:55:25 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	expand_exit_status(char *buf, size_t *i, size_t *j)
{
	char	*exit_status;

	*i += 1;
	exit_status = ft_itoa(g_last_exit);
	ft_strlcat(buf, exit_status, MAX_TOKEN_LEN);
	*j += ft_strlen(exit_status);
	free(exit_status);
}

void	expand_envvar(char *s, t_quotes_and_envvars q, size_t *i, size_t *j)
{
	char	*envvar;
	char	*str;

	q.end = 0;
	if (s[1] == '?')
	{
		expand_exit_status(q.buf, i, j);
		return ;
	}
	while (s[++q.end] != 0)
	{
		if (ft_strchr("' $", s[q.end]) || s[q.end] == '"' || s[q.end] == '\n')
		{
			q.end--;
			break ;
		}
	}
	*i += q.end;
	str = ft_substr(s, 1, q.end);
	envvar = ft_get_envvar(q.env_list, str);
	free(str);
	if (!envvar)
		return ;
	ft_strlcat(q.buf, envvar, MAX_TOKEN_LEN);
	*j += ft_strlen(envvar);
}

static int	handle_quote(char c, bool quote[2])
{
	if (c == '"' && !quote[1])
	{
		quote[0] = !quote[0];
		return (1);
	}
	if (c == 39 && !quote[0])
	{
		quote[1] = !quote[1];
		return (1);
	}
	return (0);
}

static char	*update(char *string, char *buf)
{
	if (ft_strlen(buf) > ft_strlen(string))
	{
		free(string);
		string = (char *)ft_calloc(ft_strlen(buf) + 1, sizeof(char));
	}
	ft_strlcpy(string, buf, ft_strlen(buf) + 1);
	return (string);
}

char	*quotes_and_envvars(char *string, size_t len, t_envvar *env_list)
{
	t_quotes_and_envvars	dt;

	dt.i = -1;
	dt.j = 0;
	dt.quote[0] = 0;
	dt.quote[1] = 0;
	dt.buf = (char *)ft_calloc(MAX_TOKEN_LEN, sizeof(char));
	dt.env_list = env_list;
	while (++dt.i < len)
	{
		if (handle_quote(string[dt.i], dt.quote))
			continue ;
		if (!dt.quote[1] && string[dt.i] == '$' && \
		string[dt.i + 1] != ' ' && string[dt.i + 1] != 0)
			expand_envvar((string + dt.i), dt, &dt.i, &dt.j);
		else
			dt.buf[dt.j++] = string[dt.i];
	}
	dt.buf[dt.j] = 0;
	if (ft_strcmp(dt.buf, string))
		string = update(string, dt.buf);
	free(dt.buf);
	return (string);
}
