/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:20:46 by cfabian           #+#    #+#             */
/*   Updated: 2021/12/01 18:28:35 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* not more than the number of characters specified by a parameter,are matched*/
/* The strnstr() function locates the first occurrence of the null-termi- */
/* nated string s2 in the string s1, where not more than n characters are */
/* searched.  Characters that appear after a `\0' character are not */
/* searched.  Since the strnstr() function is a FreeBSD specific API, it */
/* should only be used when portability is not a concern. */
/* If s2 is an empty string, s1 is returned; if s2 occurs nowhere in s1, */
/* NULL is returned; otherwise a pointer to the first character of the first */
/* occurrence of s2 is returned. */
#include "../libft.h"

static int	ft_cmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *str, const char *pattern, size_t len)
{
	size_t	i;
	size_t	pattern_len;

	i = 0;
	if (ft_strlen(str) < len)
		len = ft_strlen(str);
	if (*pattern == 0)
		return ((char *)str);
	if (len == 0 || *str == 0)
		return (0);
	pattern_len = ft_strlen(pattern);
	if (pattern_len > len)
		return (0);
	while (i <= len - pattern_len)
	{
		if (ft_cmp(pattern, str + i) == 0)
			return ((char *)str + i);
		i++;
	}
	return (0);
}
