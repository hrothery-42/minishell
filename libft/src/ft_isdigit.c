/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:43:22 by cfabian           #+#    #+#             */
/*   Updated: 2021/12/01 18:28:14 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* a decimal digit character. Decimal digits are 0 1 2 3 4 5 6 7 8 9. */
/* Declaration int isdigit(int c); */
/* Parameters c − This is the character to be checked. */
#include "../libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
