/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:05:36 by cfabian           #+#    #+#             */
/*   Updated: 2021/12/01 18:28:33 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (*(s1 + i))
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (*(s2 + j))
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = 0;
	return (ptr);
}
