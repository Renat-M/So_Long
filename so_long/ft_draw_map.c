/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meourea <meourea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:50:04 by meourea           #+#    #+#             */
/*   Updated: 2021/10/06 16:27:41 by meourea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_image(t_info *info)
{
	if (info->map[info->i][info->j] == '1')
		mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, \
		info->w, info->j * 50, info->i * 50);
	if (info->map[info->i][info->j] == 'P')
	{	
		mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, \
		info->k, info->j * 50, info->i * 50);
		info->pxk = info->j;
		info->pyk = info->i;
		info->map[info->i][info->j] = '0';
	}
	if (info->map[info->i][info->j] == 'C')
	{
		mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, \
		info->m, info->j * 50, info->i * 50);
		info->m_count++;
	}
	if (info->map[info->i][info->j] == 'E')
		mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, \
		info->e, info->j * 50, info->i * 50);
}

void	ft_draw_map(t_info *info)
{
	while (info->map[info->i])
	{
		info->j = 0;
		while (info->map[info->i][info->j])
		{
			ft_draw_image(info);
			info->j++;
		}
		info->i++;
	}
}
