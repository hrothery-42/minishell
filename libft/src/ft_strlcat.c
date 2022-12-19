/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:11:28 by cfabian           #+#    #+#             */
/*   Updated: 2021/12/01 18:28:33 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strlcpy() and strlcat() functions copy and concatenate strings */
/*respectively. They are designed to be safer, more consistent, and less error*/
/*prone replacements for strncpy(3) and strncat(3).  Unlike those functions, */
/*strlcpy and strlcat()take the full size of the buffer (not just the length)*/
/*and guarantee to NUL-term. the result (as long as size is larger than 0 or, */
/*in the case of strlcat(),as long as there is at least one byte free in dst).*/
/*Note that a byte for the NUL should be included in size.  Also note that */
/*strlcpy() and strlcat() only operate on true “C” strings.This means that for*/
/*strlcpy src must be NUL-terminated and for strlcat both src and dst must be*/
/*NUL-terminated.The strlcat function appends the NUL-terminated string src to*/
/*the end of dst.  It will append at most size - strlen(dst) - 1 bytes, */
/*NUL-terminating the result.*/
/*The strlcpy and strlcat functions return the total length of the string they*/
/*tried to create.For strlcpy() that means the length of src.For strlcat that*/
/*means the initial length of dst plus the length of src.  While this may seem*/
/*somewhat confusing, it was done to make truncation detection simple.*/
/*Note,that if strlcat traverses size characters without finding a NUL,*/
/*the length of the str is considered to be size and the dest string will*/
/*not be NUL-terminated (since there was no space for the NUL).  This keeps*/
/*strlcat() from running off the end of a string.  In practice this should not*/
/*happen (it means that either size is incorrect or that dst isnt a proper “C”*/
/*str).The check exists to prevent potential security probs in incorrect code.*/
#include "../libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	strl_dest;
	size_t	strl_src;

	strl_dest = ft_strlen(dest);
	strl_src = ft_strlen(src);
	if (strl_dest > size)
		return (size + strl_src);
	j = 0;
	i = strl_dest;
	while (src[j] != 0 && j + strl_dest + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (strl_dest + strl_src);
}
