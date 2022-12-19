/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_delimit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:47:33 by hrothery          #+#    #+#             */
/*   Updated: 2022/05/20 10:36:38 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*increase_buffer(int fd, char *buf)
{
	char	*more_buf;
	int		return_value;

	return_value = 1;
	more_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!more_buf)
		return (NULL);
	while (!ft_strchr(buf, '\n') && return_value)
	{
		return_value = read(fd, more_buf, BUFFER_SIZE);
		if (return_value < 0)
		{
			free(more_buf);
			return (NULL);
		}
		more_buf[return_value] = '\0';
		buf = ft_strjoin_gnl(buf, more_buf);
	}
	free (more_buf);
	return (buf);
}

static void	write_buffer(char *buf, char *out_line)
{
	int	i;

	i = 0;
	while (buf[i] != '\n' && buf[i])
	{
		out_line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		out_line[i++] = '\n';
	out_line[i] = '\0';
}

static char	*get_line(char *buf)
{
	int		i;
	char	*out_line;

	i = 0;
	if (!buf[i])
	{
		free(buf);
		return (0);
	}
	while (buf[i] != '\n' && buf[i])
		i++;
	out_line = malloc(sizeof(char) * (i + 2));
	if (!out_line)
	{
		free(buf);
		return (0);
	}
	write_buffer(buf, out_line);
	free(buf);
	return (out_line);
}

char	*gnl_delimit(int fd, char *delimiter)
{
	char		*line;
	char		*buf;

	if (fd < 0)
		return (0);
	write(1, ">", 1);
	buf = increase_buffer(fd, NULL);
	if (!buf)
		return (0);
	line = get_line(buf);
	if (!line)
	{
		print_error("minishell: warning: here-document delimited ", \
		"by end-of-file (wanted '", delimiter, "')\n");
		return (NULL);
	}
	if (!ft_strcmp(line, "\n"))
		return (line);
	if (!ft_strncmp(line, delimiter, ft_strlen(delimiter)) \
	&& ft_strlen(line) - 1 == ft_strlen(delimiter))
	{
		free(line);
		return (NULL);
	}
	return (line);
}
