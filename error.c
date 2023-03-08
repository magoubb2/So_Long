/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:39:02 by mabaron-          #+#    #+#             */
/*   Updated: 2023/03/07 14:06:43 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map_not_respected(void)
{
	ft_printf("%s", "Error\n The map you are trying to use does not \
	respect the specified regulations.");
	exit(0);
}

void	error_no_valid_entry_path(void)
{
	ft_printf("%s", "Error\n No valid entry path.");
	exit(0);
}

void	error_read(void)
{
	ft_printf("%s", "Error\n Read error.");
	exit(0);
}

void	error_wall(void)
{
	ft_printf("%s", "Error\n Your map wall or/and shape is invalid.");
	exit(0);
}

void	error_fd(void)
{
	ft_printf("%s", "Error\n There is a problem with your file descriptor.");
	exit(0);
}

void	error_memory(void)
{
	ft_printf("%s", "Error\n Not enough memory allocated");
	exit(0);
}

void	error_map_size(void)
{
	ft_printf("%s", "Error\n There is a problem with your map size.");
	exit(0);
}

void	error_length(void)
{
	ft_printf("%s", "Error\n Max length");
	exit(0);
}

void	error_invalid_path(void)
{
	ft_printf("%s", "Error\n Invalid path");
	exit(0);
}

void	error_path_c_count(void)
{
	ft_printf("%s", "Error\n Your player could not get to all \
	of your collectibles");
	exit(0);
}

void	error_exit(void)
{
	ft_printf("%s", "Error\n No access to exit");
	exit(0);
}