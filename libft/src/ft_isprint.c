/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:16:47 by cfabian           #+#    #+#             */
/*   Updated: 2021/12/01 18:28:15 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* A printable character is a character that is not a control character. */
/* Declaration int isprint(int c); */
/* Parameters c − This is the character to be checked. */
/* This function returns a non-zero value(true) if c is a */
/* printable character else, zero (false). */
#include "../libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
