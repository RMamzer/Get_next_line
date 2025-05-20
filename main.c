/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:57:23 by rmamzer           #+#    #+#             */
/*   Updated: 2025/05/20 14:18:08 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main (void)
{

	int fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	printf ("%s",get_next_line(fd));
}
