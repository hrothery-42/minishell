/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:54:02 by cfabian           #+#    #+#             */
/*   Updated: 2022/01/17 15:59:43 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* area pointed to by s for the first instance of c. Both c and the */
/* bytes of the memory area pointed to by s are interpreted as */
/* unsigned char. */
/* The memchr() and memrchr() functions return a pointer to the */
/* matching byte or NULL if the character does not occur in the */
/* given memory area. */
#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((char *)s + i) == c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
