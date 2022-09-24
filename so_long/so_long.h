/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meourea <meourea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:22:26 by meourea           #+#    #+#             */
/*   Updated: 2021/10/06 14:22:27 by meourea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_info_parc
{
	int	i;
	int	j;
	int	p;
	int	c;
	int	e;
}				t_info_parc;

typedef struct s_info
{
	int		pxk;
	int		pyk;	
	void	*k;		
	void	*w;	
	void	*b;		
	void	*m;		
	void	*e;		

	int		move_count;
	int		m_count;
	int		width_xpm;
	int		height_xpm;
	void	*mlx_ptr;
	void	*mlx_win;
	char	**map;
	int		width;
	int		height;
	int		sizex;
	int		sizey;
	int		i;
	int		j;
}				t_info;

void	ft_draw_map(t_info *info);
void	ft_movement(int move_x, int move_y, t_info *info);
char	**ft_parcer(char *file_ber);
void	ft_iniparcer(t_info_parc *info_parc);
void	ft_counter_pce(char ch, t_info_parc *info_parc);

#endif