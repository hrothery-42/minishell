/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:52:31 by cfabian           #+#    #+#             */
/*   Updated: 2022/05/20 09:14:12 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sighandler_child(int num)
{
	if (num == SIGINT)
	{
		rl_replace_line("", 0);
		printf("\n");
		exit(1);
	}
}

void	sighandler(int num)
{
	if (num == SIGINT)
	{
		g_last_exit = 130;
		rl_replace_line("", 0);
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
}
