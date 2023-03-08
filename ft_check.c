/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:23:13 by mabaron-          #+#    #+#             */
/*   Updated: 2023/03/08 10:41:03 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_check_win(void)
{
	ft_printf("%s\n", "You won gg!:D");
	exit(0);
}

void ft_check_esc(void)
{
	ft_printf("%s\n", "You exited the game.");
	exit(0);
}

int		ft_closed_window(void)
{
	ft_printf("%s", "You exited the game.");
	exit(0);
}