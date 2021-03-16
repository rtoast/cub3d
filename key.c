/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 02:17:39 by rtoast            #+#    #+#             */
/*   Updated: 2021/03/16 03:09:08 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		my_exit(int key)
{
	exit(1);
	return (1);
}

int					keybord_manager(int key, t_set *tmp)
{
	double old;
	
	if (key == 53)
		exit(1);
	if (key == 13)//w
	{
		if (ft_strchr("0WESN", tmp->map[(int)tmp->player.posy]
			[(int)(tmp->player.posx + tmp->player.dirx * 0.1)]))
			tmp->player.posx += tmp->player.dirx * 0.1;
		if (ft_strchr("0WESN", tmp->map[(int)(tmp->player.posy +
			tmp->player.diry * 0.1)][(int)tmp->player.posx]))
			tmp->player.posy += tmp->player.diry * 0.1;
		raycasting(tmp);
	}
	if (key == 0)//a
	{
		if (ft_strchr("0WESN", tmp->map[(int)tmp->player.posy]
			[(int)(tmp->player.posx + tmp->planex * 0.1)]))
			tmp->player.posx += tmp->planex * 0.1;
		if (ft_strchr("0WESN", tmp->map[(int)(tmp->player.posy +
			tmp->planey * 0.1)][(int)tmp->player.posx]))
			tmp->player.posy += tmp->planey * 0.1;
		raycasting(tmp);
	}
	if (key == 1)//s
	{
		if (ft_strchr("0WESN", tmp->map[(int)tmp->player.posy]
			[(int)(tmp->player.posx - tmp->player.dirx * 0.1)]))
			tmp->player.posx -= tmp->player.dirx * 0.1;
		if (ft_strchr("0WESN", tmp->map[(int)(tmp->player.posy -
			tmp->player.diry * 0.1)][(int)tmp->player.posx]))
			tmp->player.posy -= tmp->player.diry * 0.1;
		raycasting(tmp);
	}
	if (key == 2)//d
	{
		if (ft_strchr("0WESN", tmp->map[(int)tmp->player.posy]
			[(int)(tmp->player.posx - tmp->planex * 0.1)]))
			tmp->player.posx -= tmp->planex * 0.1;
		if (ft_strchr("0WESN", tmp->map[(int)(tmp->player.posy -
			tmp->planey * 0.1)][(int)tmp->player.posx]))
			tmp->player.posy -= tmp->planey * 0.1;
		raycasting(tmp);
	}
	if (key == 123)//<-
	{
		old = tmp->player.dirx;
		tmp->player.dirx = tmp->player.dirx * cos(-0.05) -
							tmp->player.diry * sin(-0.05);
		tmp->player.diry = old * sin(-0.05) +
							tmp->player.diry * cos(-0.05);
		old = tmp->planex;
		tmp->planex = tmp->planex * cos(-0.05) - tmp->planey * sin(-0.05);
		tmp->planey = old * sin(-0.05) + tmp->planey * cos(-0.05);
		raycasting(tmp);
	}
	if (key == 124)//->
	{
		old = tmp->player.dirx;
		tmp->player.dirx = tmp->player.dirx * cos(0.05) -
							tmp->player.diry * sin(0.05);
		tmp->player.diry = old * sin(0.05) + tmp->player.diry * cos(0.05);
		old = tmp->planex;
		tmp->planex = tmp->planex * cos(0.05) - tmp->planey * sin(0.05);
		tmp->planey = old * sin(0.05) + tmp->planey * cos(0.05);
		raycasting(tmp);
	}
	return (0);
}
