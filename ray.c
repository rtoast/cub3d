/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:59:55 by rtoast            #+#    #+#             */
/*   Updated: 2021/03/18 17:48:38 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	raycasting(t_set *tmp)
{
	int		x;
	double	mass[tmp->rx];

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
		if (tmp->raydirx < 0)
		{
			tmp->stepx = -1;
			tmp->sidedistx = (tmp->player.posx - tmp->mapx)
										* tmp->deltadistx;
		}
		else
		{
			tmp->stepx = 1;
			tmp->sidedistx = (tmp->mapx + 1.0 - tmp->player.posx)
												* tmp->deltadistx;
		}
		if (tmp->raydiry < 0)
		{
			tmp->stepy = -1;
			tmp->sidedisty = (tmp->player.posy - tmp->mapy)
											* tmp->deltadisty;
		}
		else
		{
			tmp->stepy = 1;
			tmp->sidedisty = (tmp->mapy + 1.0 - tmp->player.posy)
												* tmp->deltadisty;
		}
		while (tmp->hit == 0)
		{
			if (tmp->sidedistx < tmp->sidedisty)
			{
				tmp->sidedistx += tmp->deltadistx;
				tmp->mapx += tmp->stepx;
				if (tmp->player.posx > tmp->mapx)
					tmp->side = 1;
				else
					tmp->side = 2;
			}
			else
			{
				tmp->sidedisty += tmp->deltadisty;
				tmp->mapy += tmp->stepy;
				if (tmp->player.posy > tmp->mapy)
					tmp->side = 3;
				else
					tmp->side = 4;
			}
			if (tmp->map[tmp->mapy][tmp->mapx] == '1')
				tmp->hit = 1;
		}
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
		mass[x] = tmp->perpwalldist;
		tmp->wallx -= floor(tmp->wallx);
		tmp->lineheight = (int)(tmp->ry / tmp->perpwalldist);
		tmp->drawstart = ((tmp->lineheight * -1) / 2) + tmp->ry / 2;
		if (tmp->drawstart < 0)
			tmp->drawstart = 0;
		tmp->drawend = tmp->lineheight / 2 + tmp->ry / 2;
		if (tmp->drawend >= tmp->ry)
			tmp->drawend = tmp->ry - 1;
		texture_coordinate(tmp);
		filar(tmp, x);
	}
	colnum_sprite(tmp);
	sprite(tmp, mass);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->data.img, 0, 0);
}

void	filar(t_set *tmp, int x)
{
	int		icol;
	int		i;

	i = -1;
	while (++i < tmp->drawstart)
		my_mlx_pixel_put(&tmp->data, x, i, tmp->color_c);
	while (tmp->drawstart <= tmp->drawend)
	{
		tmp->tex_y = (int)tmp->tex_pos;
		if (tmp->side == 1 && tmp->tex_y >= tmp->tex_w.h)
			tmp->tex_y = tmp->tex_w.h - 1;
		if (tmp->side == 2 && tmp->tex_y >= tmp->tex_e.h)
			tmp->tex_y = tmp->tex_e.h - 1;
		if (tmp->side == 3 && tmp->tex_y >= tmp->tex_n.h)
			tmp->tex_y = tmp->tex_n.h - 1;
		if (tmp->side == 4 && tmp->tex_y >= tmp->tex_s.h)
			tmp->tex_y = tmp->tex_s.h - 1;
		if (tmp->tex_y < 0)
			tmp->tex_y = 0;
		tmp->tex_pos += tmp->step;
		if (tmp->side == 1)
			icol = get_color_we(tmp);
		if (tmp->side == 2)
			icol = get_color_ea(tmp);
		if (tmp->side == 3)
			icol = get_color_no(tmp);
		if (tmp->side == 4)
			icol = get_color_so(tmp);
		my_mlx_pixel_put(&tmp->data, x, tmp->drawstart++, icol);
	}
	i = tmp->drawend;
	while (++i < tmp->ry)
		my_mlx_pixel_put(&tmp->data, x, i, tmp->color_f);
}
