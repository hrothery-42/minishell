/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:03:22 by cfabian           #+#    #+#             */
/*   Updated: 2021/12/01 18:28:32 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strdup() function returns a pointer to a new string which is */
/* a duplicate of the string s.  Memory for the new string is */
/* obtained with malloc(3), and can be freed with free(3). */
/* RETURN VALUE         top */
/* On success, the strdup() function returns a pointer to the */
/* duplicated string.  It returns NULL if insufficient memory was */
/* available, with errno set to indicate the error. */
/* ERRORS         top */
/* ENOMEM Insufficient memory available to allocate duplicate string */
#include "../libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = 0;
	while (*(s + len))
		len++;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (*(s + i))
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
