/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:22:42 by cfabian           #+#    #+#             */
/*   Updated: 2021/12/01 18:28:36 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	char_in_set(char a, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (a == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ptr;

	start = 0;
	while (s1[start])
	{
		if (!char_in_set(s1[start], set))
			break ;
		start++;
	}
	end = ft_strlen(s1);
	while (end > start)
	{
		end--;
		if (!char_in_set(s1[end], set))
			break ;
	}
	end++;
	ptr = (char *)malloc(end - start + 1);
	if (ptr)
		ft_strlcpy(ptr, (s1 + start), end - start + 1);
	return (ptr);
}
