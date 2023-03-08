/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_rule.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:54:02 by mabaron-          #+#    #+#             */
/*   Updated: 2023/03/07 12:38:37 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 1. function to check how many row. */

/* 2. function to check if all the wall are '1'. */

int	nb_row(char **map)
{
	int i;
	int row_nb;
	
	i = 0;
	row_nb = 0;
	while(map[i] != 0)
	{
		row_nb++;
		i++;
	}
	return (row_nb);
}

void	side_wall_valid(t_data *data)
{
	int x; //position x
	int y; //position y

	data->n_row = nb_row(data->map);
	data->l_colum = ft_strlen(data->map[0]);
	
	y = 0;
	while (y < data->n_row)
	{
		x = 0;
		while (x < data->l_colum)
		{
			if (data->map[0][x] != '1' || data->map[data->n_row - 1][x] != '1')
				error_wall();
			if (data->map[y][0] != '1' || data->map[y][data->l_colum - 1] != '1')
				error_wall();
			x++;
		}
		y++;
	}
}
