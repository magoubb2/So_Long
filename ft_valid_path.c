/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:28:54 by mabaron-          #+#    #+#             */
/*   Updated: 2023/03/08 10:06:55 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//fonction pour determiner la position de mon player.

// duplique la map pour verifier le floodfill.
// Si la map est valide,
int	ft_c_count(char **map)
{
	int x;
	int y;
	int n_row;
	int l_colum;
	int c_count;

	l_colum = ft_strlen(map[0]);
	c_count = 0;
	y = 0;
	n_row = nb_row(map);
	while (y < n_row)
	{
		x = 0;
		while (x < l_colum)
		{
			if (map[y][x] == 'C')
			{
				c_count++;
			}
			x++;
		}
		y++;
	}
	return (c_count);
}

void	ft_floodfill(int x, int y, t_data *data, int *c_count)
{
	if (data->backup_map[x][y] == '1' || data->backup_map[x][y] == 'L' || y < 0 || x < 0)
		return ;
	if (data->backup_map[x][y] == 'C')
		*c_count -= 1;
	if (data->backup_map[x][y] == 'E')
		data->e_exit = 1;
	//printf("x: %d, y: %d\n", x, y);
	data->backup_map[x][y] = 'L';
	ft_floodfill(x - 1, y, data, c_count);
	ft_floodfill(x + 1, y, data, c_count);
	ft_floodfill(x, y - 1, data, c_count);
	ft_floodfill(x, y + 1, data, c_count);
}

void	player_pos(t_data *data, int row, int colum)
{
	while (data->backup_map[colum])
	{
		while (data->backup_map[colum][row])
		{
			if (data->backup_map[colum][row] == 'P')
			{
				data->p_x = colum;
				data->p_y = row;
				return ;
			}
			row++;
		}
		row = 0;
		colum++;
	}
}
//ft_strdup_2d

void	find_path(t_data *data)
{
	int x;
	int y;
	int c_count;
	//char **map;
	
	//y = 0;
	x = 0;
	y = 0;
	c_count = ft_c_count(data->map);
	player_pos(data, x, y);
	ft_floodfill(data->p_x, data->p_y, data, &c_count);
	if (c_count != 0 || data->e_exit != 1)
		error_exit();
}
