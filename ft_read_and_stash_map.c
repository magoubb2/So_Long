/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_stash_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:39:31 by mabaron-          #+#    #+#             */
/*   Updated: 2023/03/07 11:08:44 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(char *map)
{
	char	*store_map;
	int		fd;
	int		count;
	char	buff;

	count = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		error_fd();
	while (read(fd, &buff, 1) == 1)
	{
		count++;
	}
	if (count == 0)
		error_fd();
	store_map = ft_calloc(sizeof(char *), count + 1);
	if (!store_map)
		error_memory();
	close(fd);
	fd = open(map, O_RDONLY);
	if (read(fd, store_map, count) == -1)
		error_read();
	store_map[count] = '\0';
	return (store_map);
}

// 1.read the map to check if its O.K.

// 2. need a function to check if the fd is a .ber

/* 1.the function reads the file one byte at a time using and counts
    the number of bytes read while what is read is one 
2.allocate memory for a char array that is large 
enough to store all of the bytes read from the file.
3.this time it reads the entire contents
of the file into the newly allocated memory
4.adds a null terminator at the end of the char array, 
so that it can be treated as a string and return the store_map.*/
