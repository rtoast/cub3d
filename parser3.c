/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:36:56 by rtoast            #+#    #+#             */
/*   Updated: 2021/03/13 18:39:49 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	pars_s_(char *line, t_set *tmp)
{
	int i;
	int symbol;

	i = 0;
	symbol = 0;
	while (line[i] == 'S' || line[i] == ' ')
	{
		if (line[i] == 'S')
			symbol++;
		i++;
	}
	if (symbol != 1)
		return (-1);
	tmp->s = ft_strtrim(&line[i], " ");
	if (tmp->s == NULL)
		error_system(errno);
	return (1);
}

int	pars_ea(char *line, t_set *tmp)
{
	int i;
	int symbol;

	i = 0;
	symbol = 0;
	while (line[i] == 'E' || line[i] == ' ' || line[i] == 'A')
	{
		if (line[i] == 'E' || line[i] == 'A')
			symbol++;
		i++;
	}
	if (symbol != 2)
		return (-1);
	tmp->ea = ft_strtrim(&line[i], " ");
	if (tmp->ea == NULL)
		error_system(errno);
	return (1);
}

int	pars_we(char *line, t_set *tmp)
{
	int i;
	int symbol;

	i = 0;
	symbol = 0;
	while (line[i] == 'W' || line[i] == 'E' || line[i] == ' ')
	{
		if (line[i] == 'W' || line[i] == 'E')
			symbol++;
		i++;
	}
	if (symbol != 2)
		return (-1);
	tmp->we = ft_strtrim(&line[i], " ");
	if (tmp->we == NULL)
		error_system(errno);
	return (1);
}

int	skip(int i, char *line, int what)
{
	if (what == 1)
		while (line[i] < '0' || line[i] > '9')
			i++;
	if (what == 2)
		while (line[i] >= '0' && line[i] <= '9')
			i++;
	return (i);
}
