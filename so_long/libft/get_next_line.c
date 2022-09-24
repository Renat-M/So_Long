/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meourea <meourea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:33:26 by meourea           #+#    #+#             */
/*   Updated: 2021/10/06 16:53:58 by meourea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFFER_SIZE 10

int	chek_return(char *ending)
{
	int	i;

	if (!ending)
		return (0);
	i = 0;
	while (ending[i] != '\0')
	{
		if (ending[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(char *ending)
{
	int		i;
	char	*line;

	i = 0;
	if (!ending)
		return (0);
	while (ending[i] != '\0' && ending[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (0);
	i = 0;
	while (ending[i] != '\0' && ending[i] != '\n')
	{
		line[i] = ending[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_ending(char *ending)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!ending)
		return (0);
	while (ending[i] != '\0' && ending[i] != '\n')
		i++;
	if (ending[i] == '\0')
	{	
		free(ending);
		return (0);
	}
	str = malloc(sizeof(char) * (ft_strlen(ending) - i + 1));
	if (!str)
		return (0);
	i++;
	while (ending[i] != '\0')
		str[j++] = ending[i++];
	str[j] = '\0';
	free(ending);
	return (str);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	int			bwr;
	static char	*ending;
	char		*tmp;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line || (read(fd, 0, 0)) == -1)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	bwr = 1;
	while (!(chek_return(ending)) && (bwr))
	{
		bwr = read(fd, buff, BUFFER_SIZE);
		buff[bwr] = '\0';
		tmp = ending;
		ending = ft_strjoin(ending, buff);
		free(tmp);
	}
	*line = get_line(ending);
	ending = get_ending(ending);
	free(buff);
	if (bwr == 0)
		return (0);
	return (1);
}
