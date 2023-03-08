/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:06:20 by mabaron-          #+#    #+#             */
/*   Updated: 2023/03/08 11:00:14 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int main(void)
{
	void *mlx;
	void *win;
	//void *image;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 360, "so_long");
	
	//image = mlx_new_image(mlx, 640, 360);

	mlx_loop(mlx);
}
*/

void print_map(t_data* data)
{
	int i = 0;

	while (i < data->n_row)
	{
		printf("%s\n", data->map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data data;
	char *map;
	
	(void) argc;
	
	map = read_map(argv[1]);
	valid_map(map, &data);
	data.map = str_2d(map);
	data.backup_map = str_2d(map);
	free (map);
	side_wall_valid(&data);
	find_path(&data);
	print_map(&data);
	data.n_row = nb_row(data.backup_map);
	data.l_colum = ft_strlen(data.backup_map[0]);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.l_colum * SIZE, \
		data.n_row * SIZE, "so_long");
	ft_xpm_to_image(&data);
	ft_put_screen(&data);
	mlx_hook(data.mlx_win, 2, 0, key_motion, &data);
	mlx_hook(data.mlx_win, 17, 0, ft_closed_window, &data);
	mlx_loop(data.mlx);
}

