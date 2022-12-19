/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:42:52 by cfabian           #+#    #+#             */
/*   Updated: 2021/12/01 18:28:12 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* the passed character is alphabetic. */
/* Declaration int isalpha(int c); */
/* Parameters c − This is the character to be checked. */
/* Return Value This function returns non-zero value if */
/* c is a alphabetic, else it returns 0. */
#include "../libft.h"

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
