/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meourea <meourea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:39:29 by meourea           #+#    #+#             */
/*   Updated: 2021/10/07 16:45:48 by meourea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keyhandler(int key, t_info *info)
{
	if (key == 53)
	{
		mlx_destroy_window(info->mlx_ptr, info->mlx_win);
		exit(1);
	}
	if (key == 0)
		ft_movement(-1, 0, info);
	if (key == 1)
		ft_movement(0, 1, info);
	if (key == 2)
		ft_movement(1, 0, info);
	if (key == 13)
		ft_movement(0, -1, info);
	return (0);
}

void	ft_initialization(t_info *info)
{
	info->i = 0;
	info->j = 0;
	info->move_count = 0;
	info->m_count = 0;
	info->mlx_ptr = mlx_init();
	info->map = ft_parcer("map.ber");
	info->width = ft_strlen(info->map[0]) * 50;
	info->height = 0;
	while (info->map[info->height])
		info->height++;
	info->height *= 50;
	info->mlx_win = mlx_new_window(info->mlx_ptr, info->width, \
	info->height, "./so_long" );
	info->w = mlx_xpm_file_to_image(info->mlx_ptr, "images/wall.xpm", \
	&info->width_xpm, &info->height_xpm);
	info->k = mlx_xpm_file_to_image(info->mlx_ptr, "images/krabs.xpm", \
	&info->width_xpm, &info->height_xpm);
	info->b = mlx_xpm_file_to_image(info->mlx_ptr, "images/black.xpm", \
	&info->width_xpm, &info->height_xpm);
	info->m = mlx_xpm_file_to_image(info->mlx_ptr, "images/money.xpm", \
	&info->width_xpm, &info->height_xpm);
	info->e = mlx_xpm_file_to_image(info->mlx_ptr, "images/exit.xpm", \
	&info->width_xpm, &info->height_xpm);
}

void	ft_guard(t_info *info)
{
	if (!info->k || !info->w || !info->b || !info->m || !info->e)
	{
		write(1, "sprite error\n", 13);
		exit(-1);
	}
	if (!info->mlx_ptr || !info->mlx_win)
	{
		write(1, "mlx error\n", 10);
		exit(-1);
	}
	if (info->width > info->sizex || info->height > info->sizey)
	{
		write(1, "wrong size map", 14);
		exit(-1);
	}
}

int	ft_window_hook(t_info *info)
{
	mlx_destroy_window(info->mlx_ptr, info->mlx_win);
	exit(1);
}

int	main(void)
{
	t_info	info;

	ft_initialization(&info);
	mlx_get_screen_size(&info.mlx_ptr, &info.sizex, &info.sizey);
	ft_guard(&info);
	ft_draw_map(&info);
	mlx_hook(info.mlx_win, 17, 0L, ft_window_hook, &info);
	mlx_hook(info.mlx_win, 2, 0L, ft_keyhandler, &info);
	mlx_loop(info.mlx_ptr);
}
