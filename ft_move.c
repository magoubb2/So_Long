/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:03:21 by mabaron-          #+#    #+#             */
/*   Updated: 2023/03/08 10:41:09 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_player_move(int npp_x, int npp_y, t_data *data)
{
	if (data->map[data->p_x + npp_x][data->p_y + npp_y] != '1')
	{
		if(data->map[data->p_x + npp_x][data->p_y + npp_y] == 'E' 
			&& data->c_count == 0 && data->map[data->p_x][data->p_y] == 'P')
			ft_check_win();
		if(data->map[data->p_x + npp_x][data->p_y + npp_y] == 'E' && data->c_count != 0)
		data->w_exit = 1;
		if(data->map[data->p_x + npp_x][data->p_y + npp_y] == 'C')
			data->c_count--;
		data->map[data->p_x][data->p_y] = '0';
		if((data->w_exit == 1) && (data->map[data->p_x + npp_x][data->p_y + npp_y] != 'E'))
		{
			data->map[data->p_x][data->p_y] = 'E';
			data->w_exit = 0;
		}
		data->map[data->p_x + npp_x][data->p_y + npp_y] = 'P';
		data->p_x += npp_x;
		data->p_y += npp_y;
	}
}

int	key_motion(int keytouch, t_data *data)
{
	if (keytouch == 53)
	{
		ft_check_esc();
	}
	else if(keytouch == 13)
	{
		ft_player_move(-1, 0, data);
		ft_put_screen(data);
	}
	else if (keytouch == 2)
	{
		ft_player_move(0, 1, data);
		ft_put_screen(data);
	}
	else if (keytouch == 1)
	{
		ft_player_move(1, 0, data);
		ft_put_screen(data);
	}
	else if (keytouch == 0)
	{
		ft_player_move(0, -1, data);
		ft_put_screen(data);
	}
	return (0);
}
