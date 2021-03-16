/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:57:32 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/16 02:28:36 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	pars_map(char *line, t_set *tmp)
{
	int		i;
	int		valid;
	int		len;

	i = -1;
	len = 0;
	if (line[0] == '\0')
		tmp->linemap = 2;
	while (line[++i] != '\0')
	{
		valid = valid_symbol(line[i]);
		if (valid == 0)
			error("wrong symbol on the map");
		if (valid == 2 && tmp->play != '0')
			error("more than one player on the map");
		if (valid == 2 && ++len && tmp->play == '0')
			tmp->play = line[i];
		if (valid == 1)
			len++;
	}
	if (len > tmp->map_l)
		tmp->map_l = len;
	if (tmp->linemap == 2 && line[0] != '\0')
		error("end line splits map");
}

int		colstr(char *str)
{
	char	*line;
	int		fd;
	int		gnl;
	int		numgnl;

	line = NULL;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		error_system(errno);
	gnl = 1;
	numgnl = 0;
	while (gnl)
	{
		gnl = get_next_line(fd, &line);
		if (gnl == -1)
			error_system(errno);
		numgnl++;
		free(line);
	}
	close(fd);
	return (numgnl);
}

void	settings(t_set *tmp, int *numgnl, char **line, int fd)
{
	int		numset;

	numset = 0;
	while (numset <= 8 && *numgnl > 0)
	{
		if (get_next_line(fd, line) == -1)
			error_system(errno);
		if (pars_setting(*line, tmp) == 1)
			numset++;
		if (pars_setting(*line, tmp) == 2)
		{
			if (numset != 8)
				error("not all settings");
			break ;
		}
		tmp->mapbegin++;
		(*numgnl)--;
		free(*line);
	}
	if (*numgnl == 0)
		error("no map in file");
}

void	readfile(t_set *tmp)
{
	int		numgnl;
	int		fd;
	char	*line;
	int		i;

	numgnl = colstr("map.cub");
	line = NULL;
	fd = open("map.cub", O_RDONLY);
	if (fd < 0)
		error_system(errno);
	settings(tmp, &numgnl, &line, fd);
	pars_map(line, tmp);
	free(line);
	while (--numgnl > 0)
	{
		if (get_next_line(fd, &line) == -1)
			error_system(errno);
		pars_map(line, tmp);
		tmp->map_w++;
		free(line);
	}
	close(fd);
	if (tmp->play == '0')
		error("no player on the map");
	array_map("map.cub", tmp, tmp->mapbegin);
}

int		main(void)
{
	t_set	*tmp;

	tmp = (t_set*)malloc(sizeof(t_set));
	if (tmp == NULL)
		error_system(errno);
	tmp->play = '0';
	tmp->map_l = 0;
	tmp->linemap = 1;
	tmp->map_w = 1;
	tmp->mapbegin = 0;
	readfile(tmp);
	init(tmp);
	mlx_hook(tmp->win, 2, 0, keybord_manager, tmp);
	mlx_hook(tmp->win, 17, 0, my_exit, NULL);
	mlx_loop(tmp->mlx);
	free(tmp);
	return (0);
}
