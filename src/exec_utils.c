/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:10:20 by hrothery          #+#    #+#             */
/*   Updated: 2022/05/13 17:21:45 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_my_paths(char **paths)
{
	int	i;

	i = 0;
	if (!paths)
		return ;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

char	**find_paths(t_envvar *env_list)
{
	char	**my_paths;

	while (env_list)
	{
		if (!ft_strcmp(env_list->name, "PATH"))
		{
			my_paths = ft_split_slash(env_list->content, ':');
			return (my_paths);
		}
		env_list = env_list->next;
	}
	return (NULL);
}

char	*joined_path(char **my_paths, char *token)
{
	char	*joined_path;
	int		i;

	i = 0;
	if (!my_paths)
		return (NULL);
	while (my_paths[i])
	{
		joined_path = ft_strjoin(my_paths[i], token);
		if (!joined_path)
			return (0);
		if (access(joined_path, X_OK) == 0)
			return (joined_path);
		else
		{
			free (joined_path);
			i++;
		}
	}
	return (NULL);
}
