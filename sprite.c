/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:05:36 by rtoast            #+#    #+#             */
/*   Updated: 2021/03/23 18:19:14 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	sort_sprite(int coln, t_spr spr[])
{
	int		i;
	int		j;
	t_spr	c;

	i = 0;
	while (i < coln)
	{
		j = 0;
		while (j < coln - 1)
		{
			if (spr[j].d < spr[j + 1].d)
			{
				c = spr[j];
				spr[j] = spr[j + 1];
				spr[j + 1] = c;
			}
			j++;
		}
		i++;
	}
}

void	sp_init1(t_set *tmp, t_spr spr[], int i)
{
	tmp->spr_t.x = spr[i].x - tmp->player.posx;
	tmp->spr_t.y = spr[i].y - tmp->player.posy;
	tmp->spr_t.savetrans = 1.0 / (tmp->planex * tmp->player.diry
								- tmp->player.dirx * tmp->planey);
	tmp->spr_t.tx = tmp->spr_t.savetrans * (tmp->player.diry *
				tmp->spr_t.x - tmp->player.dirx * tmp->spr_t.y);
	tmp->spr_t.ty = tmp->spr_t.savetrans * (tmp->planex
					* tmp->spr_t.y - tmp->planey * tmp->spr_t.x);
	tmp->spr_t.camerax = (int)(tmp->rx - (tmp->rx / 2) * (1 + tmp->spr_t.tx /
													tmp->spr_t.ty));
}

void	sp_init2(t_set *tmp)
{
	tmp->spr_t.sh = abs((int)(tmp->ry / tmp->spr_t.ty));
	tmp->spr_t.sw = abs((int)(tmp->rx / tmp->spr_t.ty));
	tmp->spr_t.dstarty = tmp->ry / 2 - tmp->spr_t.sh / 2;
	tmp->spr_t.dendy = tmp->ry / 2 + tmp->spr_t.sh / 2;
	tmp->spr_t.dstartx = tmp->spr_t.camerax - tmp->spr_t.sw / 2;
	tmp->spr_t.dendx = tmp->spr_t.camerax + tmp->spr_t.sw / 2;
	if (tmp->spr_t.dstartx < 0)
		tmp->spr_t.dstartx = 0;
	if (tmp->spr_t.dstarty < 0)
		tmp->spr_t.dstarty = 0;
	if (tmp->spr_t.dendx >= tmp->rx)
		tmp->spr_t.dendx = tmp->rx - 1;
	if (tmp->spr_t.dendy >= tmp->ry)
		tmp->spr_t.dendy = tmp->ry - 1;
}

void	sp_draw(t_set *tmp, double mass[])
{
	int	color;

	while (tmp->spr_t.dstartx < tmp->spr_t.dendx)
	{
		tmp->spr_t.texx = (int)((tmp->spr_t.dstartx + tmp->spr_t.sw / 2
					- tmp->spr_t.camerax) * tmp->tex_sp.w / tmp->spr_t.sw);
		if (tmp->spr_t.ty > 0 && tmp->spr_t.ty < mass[tmp->spr_t.dstartx])
		{
			tmp->spr_t.iy = tmp->spr_t.dstarty;
			while (tmp->spr_t.iy < tmp->spr_t.dendy)
			{
				tmp->spr_t.red = 128 * (tmp->spr_t.iy * 2 -
									tmp->ry + tmp->spr_t.sh);
				tmp->spr_t.texy = tmp->spr_t.red *
							tmp->tex_sp.h / tmp->spr_t.sh / 256;
				color = get_color_spr(tmp);
				if (color != 0)
					my_mlx_pixel_put(&tmp->data, tmp->spr_t.dstartx,
												tmp->spr_t.iy, color);
				tmp->spr_t.iy++;
			}
		}
		tmp->spr_t.dstartx++;
	}
}

void	sprite(t_set *tmp, double mass[])
{
	t_spr	spr[tmp->spr_t.col_s];
	int		i;

	coordinate_sprite(tmp, spr);
	sort_sprite(tmp->spr_t.col_s, spr);
	i = 0;
	while (i < tmp->spr_t.col_s)
	{
		sp_init1(tmp, spr, i);
		sp_init2(tmp);
		sp_draw(tmp, mass);
		i++;
	}
}
