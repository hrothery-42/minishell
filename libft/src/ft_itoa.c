/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:46:02 by cfabian           #+#    #+#             */
/*   Updated: 2021/12/01 18:28:29 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* NULL if the allocation fails. */
/*External functs. malloc */
/*Description Allocates (with malloc(3)) and returns a */
/* string representing the integer received as an argument. */
/*Negative numbers must be handled.*/
#include "../libft.h"

static size_t	how_many_digits(long int n)
{
	size_t	digits;

	digits = 1;
	if (n < 0)
	{
		digits++;
		n = -n;
	}
	while (n >= 10)
	{
		digits++;
		n = n / 10;
	}
	return (digits);
}

static void	putnbr_to_str(unsigned int n, char *str, int pos)
{
	if (n >= 10)
	{
		putnbr_to_str(n / 10, str, pos - 1);
		putnbr_to_str(n % 10, str, pos);
	}
	else
		str[pos] = n + '0';
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			strlen;
	unsigned int	nbr;

	strlen = how_many_digits(n);
	str = (char *)malloc(strlen + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nbr = (unsigned int)(-n);
	}
	else
		nbr = (unsigned int)n;
	str[strlen] = 0;
	putnbr_to_str(nbr, str, strlen - 1);
	return (str);
}
