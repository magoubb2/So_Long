/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:30:54 by mabaron-          #+#    #+#             */
/*   Updated: 2023/03/07 13:55:33 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_xpm_to_image(t_data *data)
{
	int		x;
	int		y;
	char	*value;

	value = "sprite/wall.xpm";
	data->wall = mlx_xpm_file_to_image(data->mlx, value, &x, &y);
	value = "sprite/floor.xpm";
	data->floor = mlx_xpm_file_to_image(data->mlx, value, &x, &y);
	value = "sprite/door.xpm";
	data->exit = mlx_xpm_file_to_image(data->mlx, value, &x, &y);
	value = "sprite/cat.xpm";
	data->collectibles = mlx_xpm_file_to_image(data->mlx, value, &x, &y);
	value = "sprite/grandma.xpm";
	data->player = mlx_xpm_file_to_image(data->mlx, value, &x, &y);
}


void	ft_put_image_to_win(t_data *data, char aspect, int x, int y)
{
	if (aspect == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall, y, x);
	if (aspect == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, y, x);
	if (aspect == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, y, x);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->collectibles, y, x);
	}
	if (aspect == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, y, x);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, y, x);
	}
	if (aspect == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, y, x);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit, y, x);
	}
}

void	ft_put_screen(t_data *data)
{
	int x;
	int y;

	y = -1;
	while (++y < data->n_row)
	{
		x = -1;
		while (++x < data->l_colum)
			ft_put_image_to_win(data, data->map[y][x], y * SIZE, x * SIZE);
	}
}
