/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_symbol_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:30:00 by rtoast            #+#    #+#             */
/*   Updated: 2021/03/23 18:19:18 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	player_valid(t_set *tmp, int i, int j)
{
	tmp->player.posx = (double)j + 0.001;
	tmp->player.posy = (double)i + 0.001;
	if (tmp->play == 'S')
	{
		tmp->player.diry = 1;
		tmp->player.dirx = 0;
		tmp->planex = 0.66;
		tmp->planey = 0;
	}
	if (tmp->play == 'N')
	{
		tmp->player.diry = -1;
		tmp->player.dirx = 0;
		tmp->planex = -0.66;
		tmp->planey = 0;
	}
	p_valid(tmp, i, j);
}

void	valid_symbol_right(t_set *tmp, int i, int j)
{
	int	valid;
	int	ii;
	int	jj;

	valid = 0;
	ii = i;
	jj = j;
	if (tmp->map[i][j] == tmp->play)
		player_valid(tmp, i, j);
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
	if (tmp->map[i][j] == tmp->play)
		player_valid(tmp, i, j);
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
	if (tmp->map[i][j] == tmp->play)
		player_valid(tmp, i, j);
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
	if (tmp->map[i][j] == tmp->play)
		player_valid(tmp, i, j);
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
