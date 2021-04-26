/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:23:13 by rtoast            #+#    #+#             */
/*   Updated: 2021/03/23 19:18:05 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	init(t_set *tmp)
{
	tmp->mlx = mlx_init();
	tmp->win = mlx_new_window(tmp->mlx, tmp->rx, tmp->ry, "cub3D");
	tmp->data.img = mlx_new_image(tmp->mlx, tmp->rx, tmp->ry);
	tmp->data.addr = mlx_get_data_addr(tmp->data.img, &tmp->data.bpp,
								&tmp->data.line, &tmp->data.end);
	tmp->color_c = (tmp->cr << 16) + (tmp->cg << 8) + tmp->cb;
	tmp->color_f = (tmp->fr << 16) + (tmp->fg << 8) + tmp->fb;
	texture_init(tmp);
	raycasting(tmp);
}
