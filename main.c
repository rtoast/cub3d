/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:57:32 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/03 18:20:32 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		strsearch(char *line, char *sought)
{
	int	res;
	int	i;
	int	ii;
	int	len;

	res = 0;
	i = 0;
	ii = 0;
	len = ft_strlen(sought);
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		if (sought[ii] == line[i])
		{
			while(sought[ii] != '\0')
			{
				if (sought[ii] == line[i])
				{
					res++;
					ii++;
					i++;
				}
				else
					ii++;
			}
		}
		if (res == len)
			return(1);
		i++;
	}
	return (0);
}

int		pars(char *line)
{
	int		res;
	t_set	*tmp;

	tmp = (t_set*)malloc(sizeof(t_set));
	res = 1;
	tmp->rx = 0;
	if (strsearch(line, "R ") == 1)
	{
		printf("|%d|\n", pars_R(line, tmp));
		printf("%d\n", tmp->rx);
		printf("%d\n", tmp->ry);
	}
	// if (strsearch(line, "NO ") == 1)
	// 	printf("NO \n");
	// if (strsearch(line, "SO ") == 1)
	// 	printf("SO \n");
	// if (strsearch(line, "S ") == 1)
	// 	printf("S \n");
	// if (strsearch(line, "WE ") == 1)
	// 	printf("WE \n");
	// if (strsearch(line, "EA ") == 1)
	// 	printf("EA \n");
	// if (strsearch(line, "C ") == 1)
	// 	printf("C \n");
	// if (strsearch(line, "F ") == 1)
	// 	printf("F \n");
	free(tmp);
	return(res);
}
int		colstr(char *str)
{
	char	*line;
	int		fd;
	int		gnl;
	int		numgnl;

	line = NULL;
	fd = open(str, O_RDONLY);
	gnl = 1;
	numgnl = 0;
	while (gnl)
	{
		gnl = get_next_line(fd, &line);
		if (gnl == -1)
			break ;
		numgnl++;
		free (line);
	}
	close(fd);
	if (gnl == -1)
		return (-1);
	return (numgnl);
}

int		main()
{
	int		numgnl;
	int		numset;
	int		ret;
	char	*line;
	char	*str;
	int		fd;


	numgnl = colstr("map.cub");
	numset = 0;
	line = NULL;
	str = "map.cub";
	fd = open(str, O_RDONLY);
	while (numset <= 8 && numgnl > 0)
	{
		get_next_line(fd, &line);
		ret = pars(line);
		numset++;
		numgnl--;
		free (line);
	}
	close(fd);
	return (0);
}
