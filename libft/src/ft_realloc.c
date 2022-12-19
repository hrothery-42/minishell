/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:00:46 by cfabian           #+#    #+#             */
/*   Updated: 2021/12/01 18:28:28 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_realloc(void *ptr1, size_t size)
{
	void	*ptr2;

	ptr2 = (void *)ft_calloc(1, size);
	if (!ptr2)
		return (NULL);
	ft_memmove(ptr2, ptr1, ft_strlen(ptr1));
	free (ptr1);
	return (ptr2);
}
