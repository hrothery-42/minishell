/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:36:37 by cfabian           #+#    #+#             */
/*   Updated: 2022/01/20 18:25:09 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* elements of size bytes each and returns a pointer to the */
/* allocated memory.  The memory is set to zero.  If nmemb or size */
/* is 0, then calloc() returns either NULL, or a unique pointer */
/* value that can later be successfully passed to free().  If the */
/* multiplication of nmemb and size would result in integer */
/* overflow, then calloc() returns an error.  By contrast, an */
/* integer overflow would not be detected in the following call to */
/* malloc(), with the result that an incorrectly sized block of */
/* memory would be allocated: malloc(nmemb * size); */
/* The malloc() and calloc() functionen return a pointer to the */
/* allocated memory, which is suitably aligned for any built-in */
/* type.  On error, these functions return NULL.  NULL may also be */
/* returned by a successful call to malloc() with a size of zero, or */
/* by a successful call to calloc() with nmemb or size equal to */
/* zero. */
/* ERRORS         top */
/* calloc(), malloc(), realloc(), and reallocarray() can fail with */
/* the following error: */
/* ENOMEM Out of memory.  Possibly, the application hit the */
/* RLIMIT_AS or RLIMIT_DATA limit described in getrlimit(2). */
#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
