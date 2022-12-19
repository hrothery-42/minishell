/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:25:39 by cfabian           #+#    #+#             */
/*   Updated: 2021/12/01 18:28:39 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The C library function tolower converts a given letter to lowercase.*/
/* Declaration int tolower(int c); */
/* Parameters c − This is the letter to be converted to lowercase. */
/* This function returns lowercase equivalent to c, if such value exists, */
/* else c remains unchanged. The value is returned as an int value that can  */
/* be implicitly casted to char. */

#include "../libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
