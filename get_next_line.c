/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:55:27 by rmamzer           #+#    #+#             */
/*   Updated: 2025/05/20 17:52:08 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*update_output(char *buffer, char *output)
{
	size_t	buf_len;
	size_t	out_len;
	char	*new_output;

	buf_len = ft_strlen_modified(buffer);
	out_len = ft_strlen_modified(output);

	new_output = malloc(buf_len + out_len + 1);
	if (!new_output)
	// Should i assign pointer to NULL;
		return (free(output), NULL);
	if (out_len> 0)
		ft_memcpy_modified(new_output, output, out_len);
	ft_memcpy_modified(&new_output[out_len], buffer, buf_len);
	free(output);
	return (new_output);
}


void	ft_memcpy_modified(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		src[i] = '\0';
		i++;
	}
	dest[i] = '\0';
}

char	*check_buffer(char *buffer, char * output)
{
	int i;

	i = 0;
	while(i < BUFFER_SIZE )
	{
		if (buffer[i] != '\0')
			return (update_output(&buffer[i], output));
		i++;
	}
	return (output);
}


ssize_t ft_strlen_modified(char *str)
{
	ssize_t i;

	i = 0;
	if (str == NULL)
		return (0);
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
	}
	if (str[i]=='\n')
		i++;
	return (i);
}


char	*get_next_line(int fd)
{

	static char	buffer[BUFFER_SIZE +1];
	static char *output;
	ssize_t	amount_read;

	if (fd < 0 ||BUFFER_SIZE <= 0)
		return (NULL);

	output = NULL;
	output = check_buffer(buffer, output);
	amount_read = 1;
	if (output != NULL && output[ft_strlen_modified(output) -1]  == '\n')
		return (output);
	while(amount_read > 0)
	{
		amount_read = read(fd, buffer, BUFFER_SIZE);
		output = check_buffer(buffer, output);
		if (output == NULL)
			return(NULL);
		if (output[ft_strlen_modified(output) -1]  == '\n')
			return (output);
	}
	return (output);
}
