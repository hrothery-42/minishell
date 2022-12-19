/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:36:40 by cfabian           #+#    #+#             */
/*   Updated: 2022/03/21 09:43:34 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*new;

	new = (void *)ft_calloc(sizeof(t_list), 1);
	if (new)
	{
		new->content = content;
		new->next = NULL;
	}
	return (new);
}
