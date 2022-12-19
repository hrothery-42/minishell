/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:50:08 by hrothery          #+#    #+#             */
/*   Updated: 2022/05/13 11:45:41 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_envvar	*new_var(t_envvar *lst)
{
	t_envvar	*new;

	new = malloc(sizeof(t_envvar));
	if (!new)
		return (0);
	if (lst)
		lst->next = new;
	return (new);
}

t_envvar	*init_envp_list(char **envp)
{
	t_envvar	*start;
	t_envvar	*new;
	t_envvar	*var;
	int			i;

	i = 0;
	start = NULL;
	var = new_var(NULL);
	var = init_var(var, envp[i++]);
	start = var;
	while (envp[i])
	{
		new = new_var(var);
		new = init_var(new, envp[i++]);
		var = new;
	}
	return (start);
}

t_envvar	*init_var(t_envvar *var, char *envp)
{
	int	i;
	int	len;

	len = 0;
	while (envp[len] && envp[len] != '=')
		len++;
	i = len + 1;
	var->name = malloc(sizeof(char) * (len + 1));
	var->content = malloc(sizeof(char) * (ft_strlen(envp) - len));
	if (!var->name || !var->content)
		return (0);
	var->name[len] = '\0';
	while (--len >= 0)
		var->name[len] = envp[len];
	len = 0;
	while (envp[i])
		var->content[len++] = envp[i++];
	var->content[len] = '\0';
	var->next = NULL;
	return (var);
}

int	search_env_list(t_envvar *lst, char *cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cmd[i] != '=')
		i++;
	while (lst)
	{
		if (!ft_strncmp(cmd, lst->name, i) && (int)ft_strlen(lst->name) == i)
		{
			free(lst->content);
			lst->content = malloc(sizeof(char) * \
			ft_strlen(ft_strchr(cmd, '=')));
			i++;
			while (cmd[i])
				lst->content[j++] = cmd[i++];
			lst->content[j] = '\0';
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}
