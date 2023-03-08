/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:44:49 by mabaron-          #+#    #+#             */
/*   Updated: 2023/03/08 10:43:31 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h> //minilibx
# include <string.h> //pour la function strerror: This function returns a pointer to the error string describing error errnum.
# include "libft/libft.h"
# include <stdio.h>

#define SIZE 100

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	char	*m_ap;
	char	**map;
	char	**backup_map;
	int		c_count;
	char	*dup_map;
	int		p_x;
	int		p_y;
	int		n_row; //wide
	int		l_colum;
	int		e_exit;
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*collectibles;
	int		w_exit;
	
}	t_data;


		/* error mesage */	
void	error_map_not_respected(void);
void	error_no_valid_entry_path(void);
void	error_read(void);
void	error_wall(void);
void	error_fd(void);
void	error_memory(void);
void	error_map_size(void);
void	error_length(void);
void	error_invalid_path(void);
void	error_path_c_count(void);
void	error_exit(void);
int		ft_closed_window(void);


		/* parsing */
char	**str_2d(char *map);
char	*read_map(char *map);
void	valid_char(char *map);
void	valid_nb_char(char *map, t_data *data);
void	length_line(char *map);
void	valid_map(char *map, t_data *data);
void	side_wall_valid(t_data *data); 
int		nb_row(char **map);
int		ft_c_count(char **map);
void	ft_floodfill(int x, int y, t_data *data, int *c_count);
void	find_path(t_data *data);
//char	**copy_map(char **map, int n_row, int l_colum);
void	player_pos(t_data *data, int row, int colum);
void	ft_xpm_to_image(t_data *data);
void	ft_put_image_to_win(t_data *data, char aspect, int x, int y);
void	ft_put_screen(t_data *data);
void	ft_player_move(int npp_x, int npp_y, t_data *data);
void	ft_check_win(void);
int		key_motion(int keytouch, t_data *data);
void	ft_check_esc(void);

#endif

