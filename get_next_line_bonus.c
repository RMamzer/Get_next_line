/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:55:27 by rmamzer           #+#    #+#             */
/*   Updated: 2025/05/22 16:43:38 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE * (BUFFER_SIZE > 0) + 1];
	char		*output;
	int			check[1];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	output = NULL;
	*check = 0;
	output = check_buffer(buffer[fd], output, check);
	if (*check == 1)
		return (NULL);
	if (output != NULL && output[ft_strlen_modified(output) - 1] == '\n')
		return (output);
	while (read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		output = check_buffer(buffer[fd], output, check);
		if (*check == 1)
			return (NULL);
		if (output[ft_strlen_modified(output) - 1] == '\n')
			return (output);
	}
	return (output);
}
