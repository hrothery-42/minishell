/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:12:49 by cfabian           #+#    #+#             */
/*   Updated: 2021/12/01 18:28:09 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	handle_new_line(char buf[BUFFER_SIZE], char *new_line)
{
	if (ft_strchr(buf, '\n'))
	{
		ft_bzero(ft_strchr(new_line, '\n') + 1, 1);
		ft_memmove(buf, ft_strchr(buf, '\n') + 1, BUFFER_SIZE);
		return (1);
	}
	return (0);
}

static int	empty(char *line)
{
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*new_line;
	static char	fd_buf[MAX_FD][BUFFER_SIZE + 1];
	int			buf_count;
	int			end_of_file;

	buf_count = 0;
	end_of_file = 0;
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1)
		return (NULL);
	new_line = (char *)ft_calloc(sizeof(char), 1);
	while (buf_count++ >= 0)
	{
		new_line = ft_realloc(new_line, buf_count * BUFFER_SIZE);
		ft_strlcat(new_line, fd_buf[fd], buf_count * BUFFER_SIZE);
		if (handle_new_line(fd_buf[fd], new_line))
			break ;
		ft_bzero(fd_buf[fd], BUFFER_SIZE);
		if (end_of_file)
			break ;
		if (read(fd, fd_buf[fd], BUFFER_SIZE) != BUFFER_SIZE)
			end_of_file = 1;
	}
	if (!new_line || empty(new_line))
		return (NULL);
	return (new_line);
}
