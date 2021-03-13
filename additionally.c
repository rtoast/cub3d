/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionally.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:50:22 by rtoast            #+#    #+#             */
/*   Updated: 2021/03/13 18:13:10 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	error_system(int i)
{
	perror("Error\n");
	exit(i);
}

void	error(char *str)
{
	printf("Error\n%s\n", str);
	exit(1);
}

int		valid_symbol(char symbol)
{
	if (symbol == 'E' || symbol == 'W')
		return (2);
	if (symbol == 'S' || symbol == 'N')
		return (2);
	if (symbol == '0' || symbol == '1')
		return (1);
	if (symbol == '2' || symbol == ' ')
		return (1);
	else
		return (0);
}

int		strsearch(char *line, char *sought)
{
	int	res;
	int	i;
	int	ii;
	int	len;

	res = 0;
	i = -1;
	ii = 0;
	len = ft_strlen(sought);
	while (line[++i] != '\0')
	{
		if (sought[ii] == line[i])
			while (sought[ii] != '\0')
			{
				if (sought[ii] == line[i])
				{
					res++;
					i++;
				}
				ii++;
			}
		if (res == len)
			return (1);
	}
	return (0);
}

int		pars_setting(char *line, t_set *tmp)
{
	int		res;

	res = 2;
	if (strsearch(line, "R ") == 1)
		res = pars_r(line, tmp);
	if (strsearch(line, "NO ") == 1)
		res = pars_no(line, tmp);
	if (strsearch(line, "SO ") == 1)
		res = pars_so(line, tmp);
	if (strsearch(line, "S ") == 1)
		res = pars_s_(line, tmp);
	if (strsearch(line, "WE ") == 1)
		res = pars_we(line, tmp);
	if (strsearch(line, "EA ") == 1)
		res = pars_ea(line, tmp);
	if (strsearch(line, "C ") == 1)
		res = pars_c(line, tmp);
	if (strsearch(line, "F ") == 1)
		res = pars_f(line, tmp);
	if (line[0] == ' ')
		line = ft_strtrim(line, " ");
	if (line[0] == '\0')
		res = 0;
	return (res);
}
