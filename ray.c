/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:59:55 by rtoast            #+#    #+#             */
/*   Updated: 2021/03/23 18:19:09 by rtoast           ###   ########.fr       */
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
		begin_ray(tmp);
		ie(tmp);
		ray_w(tmp);
		end_ray(tmp);
		mass[x] = tmp->perpwalldist;
		texture_coordinate(tmp);
		filar(tmp, x);
	}
	colnum_sprite(tmp);
	sprite(tmp, mass);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->data.img, 0, 0);
}

void	ray_w(t_set *tmp)
{
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
}

void	ie(t_set *tmp)
{
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
}

void	filar(t_set *tmp, int x)
{
	int		icol;
	int		i;

	i = -1;
	while (++i < tmp->drawstart)
		my_mlx_pixel_put(&tmp->data, x, i, tmp->color_c);
	collor_w(tmp, x, icol);
	i = tmp->drawend;
	while (++i < tmp->ry)
		my_mlx_pixel_put(&tmp->data, x, i, tmp->color_f);
}

void	collor_w(t_set *tmp, int x, int icol)
{
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
}
