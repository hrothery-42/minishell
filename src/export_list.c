/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:44:54 by hrothery          #+#    #+#             */
/*   Updated: 2022/05/13 13:04:08 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*init_var_content(char *envp, int i)
{
	int		len;
	char	*content;

	content = malloc(sizeof(char) * (ft_strlen(envp) - i + 1));
	if (!content)
		return (0);
	len = 0;
	while (envp[i])
		content[len++] = envp[i++];
	content[len] = '\0';
	return (content);
}

t_envvar	*init_export_var(t_envvar *var, char *envp)
{
	int	i;
	int	len;

	len = 0;
	while (envp[len] && envp[len] != '=')
		len++;
	i = len;
	var->next = NULL;
	var->name = malloc(sizeof(char) * (len + 1));
	if (!var->name)
		return (0);
	var->name[len] = '\0';
	while (--len >= 0)
		var->name[len] = envp[len];
	if (!envp[i])
		var->content = NULL;
	else
		var->content = init_var_content(envp, i + 1);
	return (var);
}

static char	*replace_exp_var(char *cmd, int i, int j)
{
	char	*content;

	content = malloc(sizeof(char) * ft_strlen(ft_strchr(cmd, '=')));
	i++;
	while (cmd[i])
		content[j++] = cmd[i++];
	content[j] = '\0';
	return (content);
}

int	search_exp_list(t_envvar *lst, char *cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	lst = lst->next;
	while (cmd[i] && cmd[i] != '=')
		i++;
	while (lst)
	{
		if (!ft_strncmp(cmd, lst->name, i) && (int)ft_strlen(lst->name) == i)
		{
			if (!cmd[i])
				return (1);
			if (lst->content)
				free(lst->content);
			lst->content = replace_exp_var(cmd, i, j);
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}
