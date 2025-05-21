/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:57:23 by rmamzer           #+#    #+#             */
/*   Updated: 2025/05/21 18:37:21 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*next_line;
	int		count;

	count = 0;
	fd = open("a.out", O_RDONLY);
	if (fd == -1)
		return (1);
	// while (1)
	// {
	// 	next_line = get_next_line(fd);
	// 	if (!next_line)
	// 		break ;
	// 	count++;
	// 	printf("[%d] -> %s", count, next_line);
	// 	free (next_line);
	// 	next_line = NULL;
	// 	close  (fd);
	// }
	// close(fd);

	while (1)
	{
		next_line = get_next_line(1);
		count++;
		printf("[%d] -> %s", count, next_line);
	}
	return (0);


}
// 	#include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     FILE *file = fopen("text many n.txt", "r");  // Open your file in read mode
//     if (file == NULL)
//     {
//         perror("Error opening file");
//         return (1);
//     }

//     char *line = malloc(256);
//     size_t len = 256;
//     ssize_t read;
// 	int i = 0;
//     while ( i < 7)
//     {
// 		read = getline(&line, &len, file);
//         printf("Read %zd bytes: %s run %d\n", read, line, i);
// 		fclose(file);
// 		i++;
//     }


//     return 0;
// }
    // free(line);     // Always free the line buffer
   // fclose(file);   // Always close the file
	// while ((read = getline(&line, &len, file)) != -1)
	// 	{
	// 		printf("Read %zd bytes: %s", read, line);
	// 	}



