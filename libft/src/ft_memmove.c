/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:59:09 by cfabian           #+#    #+#             */
/*   Updated: 2021/12/01 18:28:27 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* memory area dest.  The memory areas may overlap: copying takes */
/* place as though the bytes in src are first copied into a */
/* temporary array that does not overlap src or dest, and the bytes */
/* are then copied from the temporary array to dest. */
/* RETURN VALUE */
/* The memmove() function returns a pointer to dest. */
#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if ((!src || !dest) || dest == src)
		return (dest);
	i = 0;
	if (dest <= src)
	{
		while (i < n)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			*((unsigned char *)dest + n) = *((unsigned char *)src + n);
		}
	}
	return (dest);
}
