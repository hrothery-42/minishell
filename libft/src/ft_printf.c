/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:08:05 by cfabian           #+#    #+#             */
/*   Updated: 2022/01/17 17:30:54 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	print_str(const char *str, int *printed)
{
	size_t	len;

	if (!str)
	{
		write(1, "(null)", 6);
		*printed = *printed + 6;
	}
	else
	{
		len = ft_strlen(str);
		write(1, str, len);
		*printed = *printed + len;
	}
}

static void	print_nbr(int n, int *printed)
{
	if (n == -2147483648)
	{
		print_str("-2147483648", printed);
		return ;
	}
	if (n < 0)
	{
		print_c('-', printed);
		n = n * -1;
	}
	if (n >= 10)
	{
		print_nbr(n / 10, printed);
		print_nbr(n % 10, printed);
	}
	else
		print_c(n + '0', printed);
}

static void	print_nbr_base(long long int nb, char *base, int *printed)
{
	unsigned int	base_nb;

	base_nb = ft_strlen(base);
	if (nb < 0)
	{
		print_c('-', printed);
		nb = nb * -1;
	}
	if (nb >= base_nb)
	{
		print_nbr_base(nb / base_nb, base, printed);
		print_nbr_base(nb % base_nb, base, printed);
	}
	else
		print_c(base[nb], printed);
}

static void	print_arg(const char c, va_list args, int *pr)
{
	if (c == 'c')
		print_c(va_arg(args, int ), pr);
	else if (c == 's')
		print_str(va_arg(args, char *), pr);
	else if (c == 'u' )
		print_nbr_base(va_arg(args, unsigned int ), "0123456789", pr);
	else if (c == 'd' || c == 'i' )
		print_nbr(va_arg(args, long int), pr);
	else if (c == 'p')
	{
		print_str("0x", pr);
		print_nbr_base(va_arg(args, long long int ), "0123456789abcdef", pr);
	}
	else if (c == 'x')
		print_nbr_base(va_arg(args, unsigned int ), "0123456789abcdef", pr);
	else if (c == 'X')
		print_nbr_base(va_arg(args, unsigned int ), "0123456789ABCDEF", pr);
}

int	ft_printf(const char *text, ...)
{
	int		printed;
	va_list	args;
	size_t	count;

	printed = 0;
	count = 0;
	va_start (args, text);
	while (text[count])
	{
		if (text[count] == '%')
		{
			count++;
			if (text[count] == '%')
				print_c(text[count], &printed);
			else if (ft_strchr("cspdiuxX", text[count]))
				print_arg(text[count], args, &printed);
			else
				return (0);
		}
		else
			print_c(text[count], &printed);
		count++;
	}
	va_end (args);
	return (printed);
}
