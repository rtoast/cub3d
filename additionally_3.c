/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionally_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:00:06 by rtoast            #+#    #+#             */
/*   Updated: 2021/03/23 19:05:11 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	colnum_sprite(t_set *tmp)
{
	int	i;
	int	j;

	i = 0;
	tmp->spr_t.col_s = 0;
	while (i < tmp->map_w)
	{
		j = 0;
		while (tmp->map[i][j] != '\0')
		{
			if (tmp->map[i][j] == '2')
				tmp->spr_t.col_s++;
			j++;
		}
		i++;
	}
}

void	coordinate_sprite(t_set *tmp, t_spr spr[])
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	while (i < tmp->map_w)
	{
		j = 0;
		while (tmp->map[i][j] != '\0')
		{
			if (tmp->map[i][j] == '2')
			{
				spr[s].x = j + 0.5;
				spr[s].y = i + 0.5;
				spr[s].d = pow(tmp->player.posx - spr[s].x, 2)
						+ pow(tmp->player.posy - spr[s].y, 2);
				s++;
			}
			j++;
		}
		i++;
	}
}

void	p_valid(t_set *tmp, int i, int j)
{
	if (tmp->play == 'W')
	{
		tmp->player.diry = 0;
		tmp->player.dirx = -1;
		tmp->planex = 0;
		tmp->planey = 0.66;
	}
	if (tmp->play == 'E')
	{
		tmp->player.diry = 0;
		tmp->player.dirx = 1;
		tmp->planex = 0;
		tmp->planey = -0.66;
	}
}

void	init_tmp(t_set *tmp)
{
	tmp->screen = 0;
	tmp->play = '0';
	tmp->map_l = 0;
	tmp->linemap = 1;
	tmp->map_w = 1;
	tmp->mapbegin = 0;
}
