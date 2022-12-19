/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:32:51 by hrothery          #+#    #+#             */
/*   Updated: 2022/05/18 12:35:58 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_envvar	*export_new_var(t_envvar *lst, t_envvar *new)
{
	t_envvar	*temp;
	t_envvar	*start;

	start = lst;
	while (lst->next)
	{
		if (ft_strcmp(new->name, lst->next->name) > 0)
			lst = lst->next;
		else
			break ;
	}
	if (lst->next)
	{
		temp = lst->next;
		lst->next = new;
		new->next = temp;
	}
	else
		lst->next = new;
	return (start);
}

static void	print_export_variable(t_envvar *var, int fd)
{
	ft_putstr_fd("declare -x ", fd);
	ft_putstr_fd(var->name, fd);
	if (var->content)
	{
		ft_putstr_fd("=\"", fd);
		ft_putstr_fd(var->content, fd);
		ft_putstr_fd("\"", fd);
	}
	ft_putstr_fd("\n", fd);
}

void	print_export_no_args(t_envvar *export_list, int fd)
{
	export_list = export_list->next;
	while (export_list->next)
	{
		if (ft_strcmp(export_list->name, "_"))
			print_export_variable(export_list, fd);
		export_list = export_list->next;
	}
	if (ft_strcmp(export_list->name, "_"))
		print_export_variable(export_list, fd);
}

static void	export_variable(char *cmd, t_envvar *env_list, t_envvar *exp_list)
{
	t_envvar	*new;

	if (is_alpha_numeric_underscore(cmd) != 2 && \
	!search_env_list(env_list, cmd))
		add_envvar(env_list, cmd);
	if (!search_exp_list(exp_list, cmd))
	{
		new = malloc(sizeof(t_envvar));
		new = init_export_var(new, cmd);
		export_new_var(exp_list, new);
	}
}

int	builtin_export(t_envvar *env_list, t_envvar *exp_list, char **cmd, int fd)
{
	int			i;

	i = 1;
	if (!cmd[i])
	{
		print_export_no_args(exp_list, fd);
		g_last_exit = 0;
		return (0);
	}
	while (cmd[i])
	{
		if (!is_alpha_numeric_underscore(cmd[i]))
		{
			g_last_exit = 1;
			print_error("minishell: export: '", cmd[i], \
			"': not a valid identifier\n", 0);
		}
		else
		{
			export_variable(cmd[i], env_list, exp_list);
			g_last_exit = 0;
		}
		i++;
	}
	return (0);
}
