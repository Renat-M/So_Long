/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meourea <meourea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:22:53 by meourea           #+#    #+#             */
/*   Updated: 2021/10/06 14:05:10 by meourea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_0(int move_x, int move_y, t_info *info)
{
	mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->b, \
	info->pxk * 50, info->pyk * 50);
	info->pxk += move_x;
	info->pyk += move_y;
	mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->k, \
	info->pxk * 50, info->pyk * 50);
	info->move_count++;
	ft_putnbr_fd(info->move_count, 1);
	write(1, "\n", 1);
}

void	ft_move_c(int move_x, int move_y, t_info *info)
{
	mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->b, \
	info->pxk * 50, info->pyk * 50);
	info->pxk += move_x;
	info->pyk += move_y;
	mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->b, \
	info->pxk * 50, info->pyk * 50);
	mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->k, \
	info->pxk * 50, info->pyk * 50);
	info->move_count++;
	info->m_count--;
	info->map[info->pyk][info->pxk] = '0';
	ft_putnbr_fd(info->move_count, 1);
	write(1, "\n", 1);
}

void	ft_movement(int move_x, int move_y, t_info *info)
{
	if (info->map[info->pyk + move_y][info->pxk + move_x] != '1')
	{
		if (info->map[info->pyk + move_y][info->pxk + move_x] == '0')
			ft_move_0(move_x, move_y, info);
		else if (info->map[info->pyk + move_y][info->pxk + move_x] == 'C')
			ft_move_c(move_x, move_y, info);
		else if (info->m_count == 0)
			exit(1);
	}
}
