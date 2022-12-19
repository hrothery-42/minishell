/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:40:11 by cfabian           #+#    #+#             */
/*   Updated: 2021/12/01 18:28:11 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Declaration int isalnum(int c); */
/* Parameters c − This is the character to be checked. */
/* Return Value This function returns non-zero value if c */
/* is a digit or a letter, else it returns 0. */
#include "../libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}
