/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:06:25 by hrothery          #+#    #+#             */
/*   Updated: 2022/05/13 12:10:09 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	count_list(t_envvar *env_list)
{
	int	count;

	count = 0;
	while (env_list)
	{
		env_list = env_list->next;
		count++;
	}
	return (count);
}

static char	*copy_one_list_entry(t_envvar *envvar)
{
	char	*out_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	out_str = malloc(sizeof(char) * (ft_strlen(envvar->name) + \
	ft_strlen(envvar->content) + 2));
	if (!out_str)
	{
		perror("memory allocation failed");
		exit(EXIT_FAILURE);
	}
	while (envvar->name[j])
		out_str[i++] = envvar->name[j++];
	out_str[i++] = '=';
	j = 0;
	while (envvar->content[j])
		out_str[i++] = envvar->content[j++];
	out_str[i] = '\0';
	return (out_str);
}

char	**ft_listtostr(t_envvar *env_list)
{
	char	**own_env;
	int		i;

	i = 0;
	own_env = (char **)malloc(sizeof(char *) * (count_list(env_list) + 1));
	if (!own_env)
	{
		perror("memory allocation failed");
		exit(EXIT_FAILURE);
	}
	while (env_list)
	{
		own_env[i++] = copy_one_list_entry(env_list);
		env_list = env_list->next;
	}
	own_env[i] = NULL;
	return (own_env);
}

void	ft_double_free(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
