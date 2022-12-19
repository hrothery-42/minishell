/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:26:29 by cfabian           #+#    #+#             */
/*   Updated: 2021/12/01 18:28:40 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The C library function toupper converts a given letter to uppercase. */
/* Declaration int toupper(int c); */
/* Parameters c − This is the letter to be converted to uppercase. */
/* This function returns uppercase equivalent to c, if such value exists, */
/* else c remains unchanged. The value is returned as an int value that can  */
/* be implicitly casted to char. */

#include "../libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
