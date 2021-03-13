/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_symbol_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:30:00 by rtoast            #+#    #+#             */
/*   Updated: 2021/03/13 18:52:15 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	valid_symbol_right(t_set *tmp, int i, int j)
{
	int	valid;
	int	ii;
	int	jj;

	valid = 0;
	ii = i;
	jj = j;
	while (tmp->map[ii][jj] != '\0')
	{
		if (tmp->map[ii][jj] == '1')
		{
			valid = 1;
			break ;
		}
		if (tmp->map[i][j] == ' ')
			break ;
		jj++;
	}
	if (valid == 0)
		error("incorrect map");
}

void	valid_symbol_left(t_set *tmp, int i, int j)
{
	int	valid;
	int	ii;
	int	jj;

	valid = 0;
	ii = i;
	jj = j;
	while (jj >= 0)
	{
		if (tmp->map[ii][jj] == '1')
		{
			valid = 1;
			break ;
		}
		if (tmp->map[ii][jj] == ' ')
			break ;
		jj--;
	}
	if (valid == 0)
		error("incorrect map");
}

void	valid_symbol_bottom(t_set *tmp, int i, int j)
{
	int	valid;
	int	ii;
	int	jj;

	valid = 0;
	ii = i;
	jj = j;
	while (ii >= 0)
	{
		if (tmp->map[ii][jj] == '1')
		{
			valid = 1;
			break ;
		}
		if (tmp->map[ii][jj] == ' ')
			break ;
		ii--;
	}
	if (valid == 0)
		error("incorrect map");
}

void	valid_symbol_up(t_set *tmp, int i, int j)
{
	int	valid;
	int	ii;
	int	jj;

	ii = i;
	jj = j;
	valid = 0;
	while (ii < tmp->map_w)
	{
		if (tmp->map[ii][jj] == '1')
		{
			valid = 1;
			break ;
		}
		if (tmp->map[ii][jj] == ' ' || tmp->map[ii][jj] == '\0')
			break ;
		ii++;
	}
	if (valid == 0)
		error("incorrect map");
}
