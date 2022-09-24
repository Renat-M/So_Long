/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meourea <meourea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:39:25 by meourea           #+#    #+#             */
/*   Updated: 2021/10/06 16:44:20 by meourea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_iniparcer(t_info_parc *info_parc)
{
	info_parc->i = 0;
	info_parc->j = 0;
	info_parc->p = 0;
	info_parc->c = 0;
	info_parc->e = 0;
}

void	ft_counter_pce(char ch, t_info_parc *info_parc)
{
	if (ch == 'P')
		info_parc->p++;
	if (ch == 'C')
		info_parc->c++;
	if (ch == 'E')
		info_parc->e++;
	if (ch != 'P' && ch != 'C' && ch != 'E' && ch != '1' && ch != '0')
	{
		write(1, "error: wrong map PCE\n", 21);
		exit(-1);
	}
}
