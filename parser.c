/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 21:10:00 by rtoast            #+#    #+#             */
/*   Updated: 2021/03/03 18:40:49 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	valid_R(char *line)
{
	int	i;
	int	symbol;
	int	number;

	i = 0;
	symbol = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'R')
			symbol++;
		if (line[i] == ' ' || ( line[i] >= '0' && line[i] <= '9') || line[i] == 'R')
			i++;
		else
			return(0);
	}
	if (symbol > 1)
		return (0);
	return (1);
}

int	pars_R(char *line, t_set *tmp)
{
	int	i;
	int	res;

	i = 0;
	res = valid_R(line);
	if (res == 0)
		return (0);
	while (line[i] < '0' || line[i] > '9')
		i++;
	tmp->rx = ft_atoi(&line[i]);
	if (tmp->rx == -1)
		return (0);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	tmp->ry = ft_atoi(&line[i]);
	if (tmp->ry == -1)
		return (0);
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] != '\0')
		if (line[i] == ' ')
			i++;
		else
			return (0);
	return(1);
}

// int	pars_F(char *line, t_set *tmp)
// {
// 	int i;

// 	i = 0;
// 	while (line[i] != '\0')
// 	{

// 	}
// }