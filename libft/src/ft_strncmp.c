/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:19:56 by cfabian           #+#    #+#             */
/*   Updated: 2022/05/11 11:09:59 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* s1 > s2 (first unmatching ASCI value)->return diff,only first n bytes */
#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1 && s2)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		if (*s1 == 0)
			return (0);
		i++;
		s1++;
		s2++;
	}
	return (0);
}
