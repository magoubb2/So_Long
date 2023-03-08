/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:44:58 by mabaron-          #+#    #+#             */
/*   Updated: 2023/03/08 10:08:19 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 1. check if all the character are valid */
/* 2. check if the char are the valid nb */

void	valid_map(char *map, t_data *data)
{
	valid_char(map);
	valid_nb_char(map, data);
	length_line(map);
}

void	valid_char(char *map)
{
	int i;
	
	i = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != 'P' 
			&& map[i] != 'E' && map[i] != 'C' && map[i] != '\n')
			error_map_not_respected();//return error message
		i++;
	}
}

void	valid_nb_char(char *map, t_data *data)
{
	int i;
	int nb_p;
	int nb_e;
	int nb_c;
	
	i = 0;
	nb_p = 0;
	nb_e = 0;
	nb_c = 0;
	
	while (map[i++])
	{
		if (map[i] == 'P')
			nb_p++;
		if (map[i] == 'E')
			nb_e++;
		if (map[i] == 'C')
			nb_c++;
	}
	if (nb_p != 1 || nb_e != 1 || nb_c < 1)
			error_map_not_respected();
		data->c_count = nb_c;
}

void	length_line(char *map)
 {
 	int i;
 	int first_line;
 	int other_line;
	
 	i = 0;
 	first_line = 0;
 	other_line = 0;
 	while(map[i] != '\n')
 	{
 		first_line++;
 		i++;
 	}
 	i++;
 	while(map[i] != '\0')
 	{
 		if (map[i] == '\n')
 		{
 			if (other_line != first_line)
 				error_map_size();
 			other_line = 0;
 		}
 		else
 			other_line++;
 		i++;
 	}
 }


/*void	length_line(char *name_file)
{
	size_t length;
	int fd;
	char *buff;


	fd = open(name_file, O_RDONLY);
	buff = get_next_line(fd);
	length = ft_strlen(buff);
	while (buff != NULL)
	{
		free(buff);
		buff = get_next_line(fd);
		if ( buff != NULL && length != ft_strlen(buff))
		{
			error_map_not_respected();
		}
	}
}
*/
