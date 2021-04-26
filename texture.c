/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:15:11 by rtoast            #+#    #+#             */
/*   Updated: 2021/03/23 20:00:32 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	texture_init2(t_set *tmp)
{
	if (tmp->tex_e.img == NULL)
		error_system(errno);
	tmp->tex_e.adr = mlx_get_data_addr(tmp->tex_e.img, &tmp->tex_e.bpp,
								&tmp->tex_e.line, &tmp->tex_e.end);
	tmp->tex_w.img = mlx_xpm_file_to_image(tmp->mlx, tmp->we,
								&tmp->tex_w.w, &tmp->tex_w.h);
	if (tmp->tex_w.img == NULL)
		error_system(errno);
	tmp->tex_w.adr = mlx_get_data_addr(tmp->tex_w.img, &tmp->tex_w.bpp,
								&tmp->tex_w.line, &tmp->tex_w.end);
	tmp->tex_sp.img = mlx_xpm_file_to_image(tmp->mlx,
					tmp->s, &tmp->tex_sp.w, &tmp->tex_sp.h);
	if (tmp->tex_sp.img == NULL)
		error_system(errno);
	tmp->tex_sp.adr = mlx_get_data_addr(tmp->tex_sp.img, &tmp->tex_sp.bpp,
								&tmp->tex_sp.line, &tmp->tex_sp.end);
	free(tmp->we);
	free(tmp->s);
	free(tmp->so);
}

void	texture_init(t_set *tmp)
{
	tmp->tex_s.img = mlx_xpm_file_to_image(tmp->mlx, tmp->so,
								&tmp->tex_s.w, &tmp->tex_s.h);
	if (tmp->tex_s.img == NULL)
		error_system(errno);
	tmp->tex_s.adr = mlx_get_data_addr(tmp->tex_s.img, &tmp->tex_s.bpp,
								&tmp->tex_s.line, &tmp->tex_s.end);
	tmp->tex_n.img = mlx_xpm_file_to_image(tmp->mlx, tmp->no,
								&tmp->tex_n.w, &tmp->tex_n.h);
	if (tmp->tex_n.img == NULL)
		error_system(errno);
	tmp->tex_n.adr = mlx_get_data_addr(tmp->tex_n.img, &tmp->tex_n.bpp,
								&tmp->tex_n.line, &tmp->tex_n.end);
	tmp->tex_e.img = mlx_xpm_file_to_image(tmp->mlx,
					tmp->ea, &tmp->tex_e.w, &tmp->tex_e.h);
	free(tmp->no);
	free(tmp->ea);
	texture_init2(tmp);
}

void	texture_coordinate2(t_set *tmp)
{
	if (tmp->side == 3)
	{
		tmp->tex_x = (int)(tmp->wallx * (double)tmp->tex_n.w);
		tmp->tex_x = tmp->tex_n.w - tmp->tex_x - 1;
		tmp->step = (double)tmp->tex_n.h / tmp->lineheight;
	}
	if (tmp->side == 4)
	{
		tmp->tex_x = (int)(tmp->wallx * (double)tmp->tex_s.w);
		tmp->tex_x = tmp->tex_s.w - tmp->tex_x - 1;
		tmp->step = (double)tmp->tex_s.h / tmp->lineheight;
	}
}

void	texture_coordinate(t_set *tmp)
{
	if (tmp->side == 1)
	{
		tmp->tex_x = (int)(tmp->wallx * (double)tmp->tex_w.w);
		tmp->tex_x = tmp->tex_w.w - tmp->tex_x - 1;
		tmp->step = (double)tmp->tex_w.h / tmp->lineheight;
	}
	if (tmp->side == 2)
	{
		tmp->tex_x = (int)(tmp->wallx * (double)tmp->tex_e.w);
		tmp->tex_x = tmp->tex_e.w - tmp->tex_x - 1;
		tmp->step = (double)tmp->tex_e.h / tmp->lineheight;
	}
	texture_coordinate2(tmp);
	tmp->tex_pos = tmp->step * (tmp->drawstart -
					(tmp->ry - tmp->lineheight) / 2);
}
