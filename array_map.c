/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:17:09 by rtoast            #+#    #+#             */
/*   Updated: 2021/03/13 19:05:49 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		valid_symbol_map(t_set *tmp, int i, int j)
{
	valid_symbol_right(tmp, i, j);
	valid_symbol_left(tmp, i, j);
	valid_symbol_bottom(tmp, i, j);
	valid_symbol_up(tmp, i, j);
	return (1);
}

void	valid_map(t_set *tmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < tmp->map_w)
	{
		while (tmp->map[i][j] != '\0')
			if (tmp->map[i][j] == ' ' || tmp->map[i][j] == '1')
				j++;
			else if (valid_symbol_map(tmp, i, j) == 1)
				j++;
		j = 0;
		i++;
	}
}

void	array(char *line, t_set *tmp, int i)
{
	int	j;

	j = 0;
	while (line[j] != '\0')
	{
		tmp->map[i][j] = line[j];
		j++;
	}
}

void	malloc_array(t_set *tmp, int fd, char *line, int l)
{
	int i;

	i = -1;
	tmp->map = (char**)malloc(tmp->map_w * sizeof(char*));
	if (tmp->map == NULL)
		error_system(errno);
	while (++i < tmp->map_w)
	{
		tmp->map[i] = (char*)ft_calloc((tmp->map_l + 1), sizeof(char));
		if (tmp->map[i] == NULL)
			error_system(errno);
	}
	while (l-- != 0)
	{
		if (get_next_line(fd, &line) == -1)
			error_system(errno);
		free(line);
	}
}

void	array_map(char *str, t_set *tmp, int l)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		error_system(errno);
	malloc_array(tmp, fd, line, l);
	i = -1;
	l = 1;
	while (l)
	{
		l = get_next_line(fd, &line);
		if (l == -1)
			error_system(errno);
		array(line, tmp, ++i);
		free(line);
	}
	close(fd);
	valid_map(tmp);
}
