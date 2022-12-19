/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:58:15 by cfabian           #+#    #+#             */
/*   Updated: 2021/12/01 18:28:27 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The memcpy() function copies n bytes from memory area src to */
/* memory area dest.  The memory areas must not overlap.  Use */
/* memmove(3) if the memory areas do overlap. */
/* RETURN VALUE         */
/* The memcpy() function returns a pointer to dest. */
/* Failure to observe the requirement that the memory areas do not */
/* overlap has been the source of significant bugs.  (POSIX and the */
/* C standards are explicit that employing memcpy() with overlapping */
/* areas produces undefined behavior.) */
/* Note that the purpose of restrict is to show only syntax. It doesn't */
/* cange anything in output (or logic). It is just a way for programmer */
/* to tell compiler about an optimization  */
#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dest)
		return (dest);
	i = 0;
	while (i < n)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}
