/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:56:30 by rmamzer           #+#    #+#             */
/*   Updated: 2025/05/15 16:57:45 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//INITIAL FOR BUFER, WILL I NEED IT?
# define BUFFER 5
// read function
# include <unistd.h>

//DELEEEEEEEEEEEEEEEEEEEEEETE: PRINTFF
# include <stdio.h>




char	*get_next_line(int fd);


#endif

