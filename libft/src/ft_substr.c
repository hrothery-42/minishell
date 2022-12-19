/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:24:53 by cfabian           #+#    #+#             */
/*   Updated: 2022/05/04 19:30:28 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr_strip_space(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (NULL);
	if (s_len - start < len)
		len = s_len - start;
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (0);
	while (s[start] == ' ')
	{
		start++;
		len--;
	}
	i = start;
	while (i - start < len && *(s + i) != 0)
	{
		ptr[i - start] = s[i];
		i++;
	}
	ptr[i - start] = 0;
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (s_len - start < len)
		len = s_len - start;
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (0);
	i = start;
	while (i - start < len && *(s + i) != 0)
	{
		ptr[i - start] = s[i];
		i++;
	}
	ptr[i - start] = 0;
	return (ptr);
}
