/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 20:52:54 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/23 18:19:12 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	begin_ray(t_set *tmp)
{
	tmp->raydirx = tmp->player.dirx + tmp->planex * tmp->camerax;
	tmp->raydiry = tmp->player.diry + tmp->planey * tmp->camerax;
	tmp->mapx = (int)tmp->player.posx;
	tmp->mapy = (int)tmp->player.posy;
	tmp->deltadistx = fabs(1 / tmp->raydirx);
	tmp->deltadisty = fabs(1 / tmp->raydiry);
	tmp->hit = 0;
}

void	end_ray(t_set *tmp)
{
	if (tmp->side < 3)
	{
		tmp->perpwalldist = (tmp->mapx - tmp->player.posx +
					(1 - tmp->stepx) / 2) / tmp->raydirx;
		tmp->wallx = tmp->player.posy + tmp->perpwalldist * tmp->raydiry;
	}
	else
	{
		tmp->perpwalldist = (tmp->mapy - tmp->player.posy +
						(1 - tmp->stepy) / 2) / tmp->raydiry;
		tmp->wallx = tmp->player.posx + tmp->perpwalldist * tmp->raydirx;
	}
	tmp->wallx -= floor(tmp->wallx);
	tmp->lineheight = (int)(tmp->ry / tmp->perpwalldist);
	tmp->drawstart = ((tmp->lineheight * -1) / 2) + tmp->ry / 2;
	if (tmp->drawstart < 0)
		tmp->drawstart = 0;
	tmp->drawend = tmp->lineheight / 2 + tmp->ry / 2;
	if (tmp->drawend >= tmp->ry)
		tmp->drawend = tmp->ry - 1;
}
