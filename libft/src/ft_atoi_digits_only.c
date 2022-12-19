/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_digits_only.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:39:21 by cfabian           #+#    #+#             */
/*   Updated: 2022/01/17 17:58:34 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* pointed to by nptr to int.  The behavior is the same as */
/* strtol(nptr, NULL, 10); except that atoi() does not detect errors. */
/* RETURN VALUE         top */
/* The converted value or 0 on error. */

#include "../libft.h"
#include <stdio.h>

int	ft_atoi_d_only(const char *str)
{
	unsigned int		i;
	unsigned long int	num;
	int					s;

	i = 0;
	num = 0;
	s = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		s = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((s == -1 && num == INT_MAX / 10 && (str[i] - '1') > INT_MAX % 10)
			|| (s == 1 && num == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)
			|| (num > INT_MAX / 10))
			break ;
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (s * num);
}

/*
int main ()
{
	printf("+012345: %d\n", ft_atoi("+012345"));
	printf("-1569: %d\n", ft_atoi("-1569"));
	printf("-+156: %d\n", ft_atoi("-+156"));
	printf("12345n: %d\n", ft_atoi("12345n"));
	printf("int_max is %d; int_min is %d \n", INT_MAX, INT_MIN);
	printf("+02147483647: %d \n", ft_atoi("+02147483647"));
	printf("+2147483648: %d \n", ft_atoi("+2147483648"));
	printf("+2147483657: %d \n", ft_atoi("+2147483657"));
	printf("+21474836470: %d \n", ft_atoi("+21474836470"));
	printf("-2147483648: %d \n", ft_atoi("-2147483648"));
	printf("-2147483649: %d \n", ft_atoi("-2147483649"));
}
*/