/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:59:55 by rtoast            #+#    #+#             */
/*   Updated: 2021/03/16 03:05:25 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	raycasting(t_set *tmp)
{
	int	x;

	x = -1;
	while (++x < tmp->rx)
	{
		tmp->camerax = 2 - 2 * x / (double)tmp->rx - 1;
		tmp->raydirx = tmp->player.dirx + tmp->planex * tmp->camerax;
		tmp->raydiry = tmp->player.diry + tmp->planey * tmp->camerax;
		tmp->mapx = (int)tmp->player.posx;
		tmp->mapy = (int)tmp->player.posy;
		tmp->deltadistx = fabs(1 / tmp->raydirx);
		tmp->deltadisty = fabs(1 / tmp->raydiry);
		tmp->hit = 0;
		if(tmp->raydirx < 0)
		{
			tmp->stepx = -1;
			tmp->sidedistx = (tmp->player.posx - tmp->mapx) * tmp->deltadistx;
		}
		else
		{
		tmp->stepx = 1;
		tmp->sidedistx = (tmp->mapx + 1.0 - tmp->player.posx) * tmp->deltadistx;
		}
		if(tmp->raydiry < 0)
		{
			tmp->stepy = -1;
			tmp->sidedisty = (tmp->player.posy - tmp->mapy) * tmp->deltadisty;
		}
		else
		{
 			tmp->stepy = 1;
			tmp->sidedisty = (tmp->mapy + 1.0 - tmp->player.posy) * tmp->deltadisty;
		}
		while (tmp->hit == 0)
		{
			if(tmp->sidedistx < tmp->sidedisty)
			{
				tmp->sidedistx += tmp->deltadistx;
				tmp->mapx += tmp->stepx;
				tmp->side = 0;
			}
			else
			{
				tmp->sidedisty += tmp->deltadisty;
				tmp->mapy += tmp->stepy;
				tmp->side = 1;
			}
			if(tmp->map[tmp->mapy][tmp->mapx] == '1')
			tmp->hit = 1;
		}
		if(tmp->side == 0)
			tmp->perpwalldist = (tmp->mapx - tmp->player.posx + (1 - tmp->stepx) / 2) / tmp->raydirx;
		else
			tmp->perpwalldist = (tmp->mapy - tmp->player.posy + (1 - tmp->stepy) / 2) / tmp->raydiry;
		tmp->lineheight = (int)(tmp->ry / tmp->perpwalldist);
		tmp->drawstart = -tmp->lineheight / 2 + tmp->ry / 2;
		if(tmp->drawstart < 0)
			tmp->drawstart = 0;
		tmp->drawend = tmp->lineheight / 2 + tmp->ry / 2;
		if(tmp->drawend >= tmp->ry)
			tmp->drawend = tmp->ry - 1;
		filar(tmp, x);
	}
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->data.img, 0, 0);
}

void	filar(t_set *tmp, int x)
{
	int		color;
	int		i;

	i = -1;
	if (tmp->side == 0)
		color = 0xFF0000;
	else
		color = 0x00FF00;
	while (++i < tmp->drawstart)
		my_mlx_pixel_put(&tmp->data.img, x, i, tmp->color_c);
	while (tmp->drawstart <= tmp->drawend)
		my_mlx_pixel_put(&tmp->data.img, x, tmp->drawstart++, color);
	i = tmp->drawend;
	while (++i < tmp->ry)
		my_mlx_pixel_put(&tmp->data.img, x, i, tmp->color_f);
}
