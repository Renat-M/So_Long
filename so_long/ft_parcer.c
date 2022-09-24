/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meourea <meourea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:35:34 by meourea           #+#    #+#             */
/*   Updated: 2021/10/06 18:03:30 by meourea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_chek_pce(char **map, t_info_parc *info_parc)
{
	while (map[info_parc->i])
	{
		while (map[info_parc->i][info_parc->j])
		{
			ft_counter_pce(map[info_parc->i][info_parc->j], info_parc);
			info_parc->j++;
		}
		info_parc->j = 0;
		info_parc->i++;
	}
	if (info_parc->p != 1 || info_parc->c == 0 || info_parc->e == 0)
	{
		write(1, "error: wrong map PCE\n", 21);
		exit(-1);
	}
}

void	ft_check_walls(char **map, t_info_parc *info_parc)
{
	info_parc->i = 0;
	while (map[info_parc->i] != NULL)
	{
		if (info_parc->i == 0 || map[info_parc->i + 1] == NULL)
		{
			info_parc->j = 0;
			while (map[info_parc->i][info_parc->j])
			{
				if (map[info_parc->i][info_parc->j] != '1')
				{
					write(1, "error: wrong map WALLS\n", 23);
					exit(-1);
				}
				info_parc->j++;
			}
		}		
		else if (map[info_parc->i][0] != '1' || map[info_parc->i] \
		[ft_strlen(map[info_parc->i]) - 1] != '1')
		{
			write(1, "error: wrong map WALLS\n", 23);
			exit(-1);
		}
		info_parc->i++;
	}
}

void	ft_check_rectangle(char **map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (len != ft_strlen(map[i]))
		{
			write(1, "error: not rectangle\n", 21);
			exit(-1);
		}
		i++;
	}
}

int	ft_counter_lines(char *file_ber)
{
	int		fd;
	int		i;
	char	*tmp;

	fd = open(file_ber, O_RDONLY);
	if (fd == -1)
	{
		write(1, "error: no map\n", 14);
		exit (-1);
	}
	i = 0;
	while (get_next_line(fd, &tmp))
	{
		i++;
		free(tmp);
	}
	free(tmp);
	i++;
	close(fd);
	return (i);
}

char	**ft_parcer(char *file_ber)
{
	int			fd;
	char		**map;
	int			i;
	int			counter;
	t_info_parc	info_parc;

	i = 0;
	ft_iniparcer(&info_parc);
	counter = ft_counter_lines(file_ber);
	fd = open(file_ber, O_RDONLY);
	map = malloc(sizeof(char *) * (counter + 1));
	if (!map)
	{	
		write(1, "malloc error\n", 13);
		exit (-1);
	}
	while (counter > 0)
		counter = get_next_line(fd, &map[i++]);
	map[i] = NULL;
	ft_chek_pce(map, &info_parc);
	ft_check_walls(map, &info_parc);
	ft_check_rectangle(map);
	close(fd);
	return (map);
}
