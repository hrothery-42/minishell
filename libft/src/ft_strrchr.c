/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:21:20 by cfabian           #+#    #+#             */
/*   Updated: 2021/12/01 18:28:36 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strrchr() function returns a pointer to the last occurrence */
/* of the character c in the string s. */
/* Here "character" means "byte"; these functions do not work with */
/* wide or multibyte characters. */
/* The strchr() and strrchr() functions return a pointer to the */
/* matched character or NULL if the character is not found.  The */
/* terminating null byte is considered part of the string, so that */
/* if c is specified as '\0', these functions return a pointer to */
/* the terminator. */
#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	if (c == 0)
		return ((char *)s + i);
	while (i > 0)
	{
		i--;
		if (*(s + i) == c)
			return ((char *)s + i);
	}
	return (0);
}
