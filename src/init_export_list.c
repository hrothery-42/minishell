/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_export_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:24:37 by hrothery          #+#    #+#             */
/*   Updated: 2022/05/18 12:33:58 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	add_var_to_list_cont(t_envvar *lst, t_envvar *new)
{
	t_envvar	*tmp;

	if (lst->next)
	{
		tmp = lst->next;
		lst->next = new;
		new->next = tmp;
	}
	else
		lst->next = new;
}

t_envvar	*add_var_to_list(t_envvar *lst, t_envvar *new)
{
	t_envvar	*start;

	if (ft_strcmp(new->name, lst->name) <= 0)
	{
		start = new;
		new->next = lst;
		return (start);
	}
	start = lst;
	while (lst->next)
	{
		if (ft_strcmp(new->name, lst->next->name) > 0)
			lst = lst->next;
		else
			break ;
	}
	add_var_to_list_cont(lst, new);
	return (start);
}

t_envvar	*duplicate_variable(t_envvar *lst, t_envvar *new)
{
	int			i;

	i = 0;
	new->name = malloc(sizeof(char) * (ft_strlen(lst->name) + 1));
	while (lst->name[i])
	{
		new->name[i] = lst->name[i];
		i++;
	}
	new->name[i] = '\0';
	new->content = malloc(sizeof(char) * (ft_strlen(lst->content) + 1));
	i = 0;
	while (lst->content[i])
	{
		new->content[i] = lst->content[i];
		i++;
	}
	new->content[i] = '\0';
	new->next = NULL;
	return (new);
}

t_envvar	*create_first_export_var(t_envvar *exp_list)
{
	t_envvar	*new;

	new = malloc(sizeof(t_envvar));
	new->name = malloc(sizeof(char) * 10);
	new->name[0] = 'E';
	new->name[1] = 'X';
	new->name[2] = 'P';
	new->name[3] = 'R';
	new->name[4] = '?';
	new->name[5] = 'L';
	new->name[6] = 'S';
	new->name[7] = 'T';
	new->name[8] = '0';
	new->name[9] = '\0';
	new->content = NULL;
	new->next = exp_list;
	return (new);
}

t_envvar	*duplicate_list(t_envvar *lst)
{
	t_envvar	*new_list;
	t_envvar	*new;

	new = new_var(NULL);
	if (lst)
	{
		new = duplicate_variable(lst, new);
		new_list = new;
	}
	while (lst->next)
	{
		lst = lst->next;
		new = new_var(NULL);
		new = duplicate_variable(lst, new);
		new_list = add_var_to_list(new_list, new);
	}
	new_list = create_first_export_var(new_list);
	return (new_list);
}
