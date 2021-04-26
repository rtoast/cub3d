/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 21:10:00 by rtoast            #+#    #+#             */
/*   Updated: 2021/03/23 18:19:01 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	retur_f(t_set *tmp, int i, char *line, int j)
{
	if (i == 1)
		if (tmp->fr < 0 || tmp->fr > 255)
			error("not valid color");
	if (i == 2)
		if (tmp->fg < 0 || tmp->fg > 255)
			error("not valid color");
	if (i == 3)
		if (tmp->fb < 0 || tmp->fb > 255)
			error("not valid color");
	if (i == 4)
		while (line[j] != '\0')
		{
			if (line[j] == ' ')
				j++;
			else
				error("error color settings");
		}
	return (1);
}

int	valid_r(char *line)
{
	int	i;
	int	symbol;

	i = 0;
	symbol = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'R')
			symbol++;
		if (line[i] == ' ' || (line[i] >= '0' && line[i] <= '9')
							|| line[i] == 'R')
			i++;
		else
			return (0);
	}
	if (symbol > 1)
		return (0);
	return (1);
}

int	pars_r(char *line, t_set *tmp)
{
	int	i;
	int	res;

	i = 0;
	res = valid_r(line);
	if (res == 0)
		return (-1);
	i = skip(i, line, 1);
	tmp->rx = ft_atoi(&line[i]);
	if (tmp->rx == -1)
		return (-1);
	i = skip(i, line, 2);
	tmp->ry = ft_atoi(&line[i]);
	if (tmp->ry == -1)
		return (0);
	i = skip(i, line, 1);
	i = skip(i, line, 2);
	while (line[i] != '\0')
		if (line[i] == ' ')
			i++;
		else
			return (-1);
	if (tmp->rx == 0 || tmp->ry == 0)
		error("R parameters error");
	return (max_r(tmp));
}

int	valid_f(char *line, int *comma)
{
	int	i;
	int	symbol;

	i = 0;
	symbol = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'F')
			symbol++;
		if (line[i] == ',')
			(*comma)++;
		if (line[i] == ' ' || (line[i] >= '0' && line[i] <= '9')
			|| line[i] == 'F' || line[i] == ',')
			i++;
		else
			return (0);
	}
	if (symbol > 1)
		return (0);
	return (1);
}

int	pars_f(char *line, t_set *tmp)
{
	int	i;
	int	comma;
	int	res;
	int	ret;

	i = 0;
	comma = 0;
	res = valid_f(line, &comma);
	if (res == 0 || comma != 2)
		return (-1);
	i = skip(i, line, 1);
	tmp->fr = ft_atoi(&line[i]);
	ret = retur_f(tmp, 1, line, i);
	i = skip(i, line, 2);
	i = skip(i, line, 1);
	tmp->fg = ft_atoi(&line[i]);
	ret = retur_f(tmp, 2, line, i);
	i = skip(i, line, 2);
	i = skip(i, line, 1);
	tmp->fb = ft_atoi(&line[i]);
	ret = retur_f(tmp, 3, line, i);
	i = skip(i, line, 2);
	ret = retur_f(tmp, 4, line, i);
	return (1);
}
