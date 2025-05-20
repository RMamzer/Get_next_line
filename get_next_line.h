/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:56:30 by rmamzer           #+#    #+#             */
/*   Updated: 2025/05/20 16:53:27 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H



# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// read function
# include <unistd.h>
//size_t
# include <stdlib.h>

//DELEEEEEEEEEEEEEEEEEEEEEETE: PRINTFF
# include <stdio.h>




char	*get_next_line(int fd);
char	*update_output(char *buffer, char *output);
void	ft_memcpy_modified(char *dest, char *src, size_t n);
char	*check_buffer(char *buffer, char * output);
ssize_t	ft_strlen_modified(char *str);
#endif

