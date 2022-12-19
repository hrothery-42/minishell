/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:50:41 by hrothery          #+#    #+#             */
/*   Updated: 2022/04/01 14:51:12 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_copystring_gnl(char *s1, char *s2, char *s3)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	free (s1);
	return (s3);
}

char	*ft_strjoin_gnl(char *s1, char*s2)
{
	char	*out_str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	out_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (out_str == 0)
		return (0);
	out_str = ft_copystring_gnl(s1, s2, out_str);
	return (out_str);
}
