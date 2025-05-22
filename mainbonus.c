/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainbonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:24:46 by rmamzer           #+#    #+#             */
/*   Updated: 2025/05/22 17:05:59 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*next_line1;
	char	*next_line2;
	int		count;

	count = 0;
	fd1 = open("text full.txt", O_RDONLY);
	fd2 = open("text bonus.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
		return (1);
	while (1)
	{
		next_line1 = get_next_line(fd1);
		if (!next_line1)
			break ;
		next_line2 = get_next_line(fd2);
		if (!next_line2)
			break ;
		count++;
		printf("fd1 - %d -> %s", count, next_line1);
		free (next_line1);
		printf("fd2 - %d -> %s", count, next_line2);
		free (next_line2);
	}
	close(fd1);
	close(fd2);
	return (0);
}
