/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:56:35 by hrothery          #+#    #+#             */
/*   Updated: 2022/05/13 14:09:46 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_envvar(t_envvar *env_list, char *s)
{
	while (env_list)
	{
		if (!ft_strcmp(env_list->name, s))
			return (env_list->content);
		env_list = env_list->next;
	}
	return (0);
}

int	is_alpha_numeric_underscore(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (!ft_isalpha(s[0]))
		return (0);
	while (s[i] && (s[i] == '_' || ft_isdigit(s[i]) || ft_isalpha(s[i])))
		i++;
	if (s[i] == '=')
		return (1);
	if (!s[i])
		return (2);
	return (0);
}

void	add_export_envvar(t_envvar *lst, char *s)
{
	t_envvar	*new;

	while (lst->next && ft_strcmp(lst->next->name, "_"))
		lst = lst->next;
	new = malloc(sizeof(t_envvar));
	if (!new)
		return ;
	lst->next = new;
	new = init_export_var(new, s);
}

void	add_envvar(t_envvar *lst, char *s)
{
	t_envvar	*new;
	t_envvar	*temp;

	while (lst->next && ft_strcmp(lst->next->name, "_"))
		lst = lst->next;
	temp = lst->next;
	new = malloc(sizeof(t_envvar));
	if (!new)
		return ;
	lst->next = new;
	new = init_var(new, s);
	new->next = temp;
}
