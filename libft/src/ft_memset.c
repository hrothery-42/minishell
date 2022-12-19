/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:00:07 by cfabian           #+#    #+#             */
/*   Updated: 2021/12/01 18:28:28 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* character c (an unsigned char) to the first n characters of the string */
/* pointed to, by the argument str. */
/* Declaration void *memset(void *str, int c, size_t n) */
/* Parameters */
/* str − This is a pointer to the block of memory to fill. */
/* c − value to be set. The value is passed as an int, but the function */
/*fills the block of memory using the unsigned char conversion of this value.*/
/* n − This is the number of bytes to be set to the value. */
/* This function returns a pointer to the memory area str. */
#include "../libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)str + i) = c;
		i++;
	}
	return (str);
}
