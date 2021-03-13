/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 02:26:40 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/13 18:51:22 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	valid_c(char *line, int *comma)
{
	int	i;
	int	symbol;

	i = 0;
	symbol = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'C')
			symbol++;
		if (line[i] == ',')
			(*comma)++;
		if (line[i] == ' ' || (line[i] >= '0' && line[i] <= '9')
			|| line[i] == 'C' || line[i] == ',')
			i++;
		else
			return (0);
	}
	if (symbol > 1)
		return (0);
	return (1);
}

int	retur_c(t_set *tmp, int i, char *line, int j)
{
	if (i == 1)
		if (tmp->cr < 0 || tmp->cr > 255)
			error("not valid color");
	if (i == 2)
		if (tmp->cg < 0 || tmp->cg > 255)
			error("not valid color");
	if (i == 3)
		if (tmp->cb < 0 || tmp->cb > 255)
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

int	pars_c(char *line, t_set *tmp)
{
	int	i;
	int	comma;
	int	res;
	int	ret;

	i = 0;
	comma = 0;
	res = valid_c(line, &comma);
	if (res == 0 || comma != 2)
		return (-1);
	i = skip(i, line, 1);
	tmp->cr = ft_atoi(&line[i]);
	ret = retur_c(tmp, 1, line, i);
	i = skip(i, line, 2);
	i = skip(i, line, 1);
	tmp->cg = ft_atoi(&line[i]);
	ret = retur_c(tmp, 2, line, i);
	i = skip(i, line, 2);
	i = skip(i, line, 1);
	tmp->cb = ft_atoi(&line[i]);
	ret = retur_c(tmp, 3, line, i);
	i = skip(i, line, 2);
	ret = retur_c(tmp, 4, line, i);
	return (ret);
}

int	pars_no(char *line, t_set *tmp)
{
	int i;
	int symbol;

	i = 0;
	symbol = 0;
	while (line[i] == 'N' || line[i] == 'O' || line[i] == ' ')
	{
		if (line[i] == 'N' || line[i] == 'O')
			symbol++;
		i++;
	}
	if (symbol != 2)
		return (-1);
	tmp->no = ft_strtrim(&line[i], " ");
	if (tmp->no == NULL)
		error_system(errno);
	return (1);
}

int	pars_so(char *line, t_set *tmp)
{
	int i;
	int symbol;

	i = 0;
	symbol = 0;
	while (line[i] == 'S' || line[i] == 'O' || line[i] == ' ')
	{
		if (line[i] == 'S' || line[i] == 'O')
			symbol++;
		i++;
	}
	if (symbol != 2)
		return (-1);
	tmp->so = ft_strtrim(&line[i], " ");
	if (tmp->so == NULL)
		error_system(errno);
	return (1);
}
