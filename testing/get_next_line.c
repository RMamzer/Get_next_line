/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:36:01 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/19 13:01:52 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*process_buffer(char *buffer, char *line);
static char	*ft_strjoin_and_erase(char *line, char *buffer);

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	buffer[BUFFER_SIZE] = '\0';
	line = NULL;
	line = process_buffer(buffer, line);
	if (line != NULL && line[ft_strlen_new_line(line) - 1] == '\n')
		return (line);
	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, (void *) buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(line), line = NULL, NULL);
		line = process_buffer(buffer, line);
		if (line != NULL && line[ft_strlen_new_line(line) - 1] == '\n')
			return (line);
	}
	return (line);
}

static char	*process_buffer(char *buffer, char *line)
{
	int		i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] != 0)
		{
			line = ft_strjoin_and_erase(line, &buffer[i]);
			return (line);
		}
		i++;
	}
	return (line);
}

static char	*ft_strjoin_and_erase(char *line, char *buffer)
{
	size_t	buffer_len;
	size_t	line_len;
	char	*temp;

	buffer_len = ft_strlen_new_line(buffer);
	line_len = ft_strlen_new_line(line);
	temp = malloc(sizeof(char) * (line_len + buffer_len + 1));
	if (temp == NULL)
		return (free(line), line = NULL, NULL);
	ft_copy_and_erase(temp, line, line_len);
	ft_copy_and_erase(&temp[line_len], buffer, buffer_len);
	temp[line_len + buffer_len] = '\0';
	return (free(line), temp);
}
