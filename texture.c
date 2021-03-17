/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:15:11 by rtoast            #+#    #+#             */
/*   Updated: 2021/03/17 05:39:48 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	tmp->tex_pos = tmp->step * (tmp->drawstart -
					(tmp->ry - tmp->lineheight) / 2);
}

int		get_color_we(t_set *tmp)
{
	int	icol;

	tmp->tex_x = abs(tmp->tex_x);
	tmp->tex_y = abs(tmp->tex_y);
	if (!tmp->tex_w.h || !tmp->tex_w.w)
		return (0);
	if (tmp->tex_x > tmp->tex_w.w || tmp->tex_y > tmp->tex_w.h)
		return (0);
	icol = (*(int*)(tmp->tex_w.adr + ((tmp->tex_x + (tmp->tex_y * tmp->tex_w.w))
				* (tmp->tex_w.bpp / 8))));
	return (icol);
}

int		get_color_ea(t_set *tmp)
{
	int	icol;

	tmp->tex_x = abs(tmp->tex_x);
	tmp->tex_y = abs(tmp->tex_y);
	if (!tmp->tex_e.h || !tmp->tex_e.w)
		return (0);
	if (tmp->tex_x > tmp->tex_e.w || tmp->tex_y > tmp->tex_e.h)
		return (0);
	icol = (*(int*)(tmp->tex_e.adr + ((tmp->tex_x + (tmp->tex_y * tmp->tex_e.w))
													* (tmp->tex_e.bpp / 8))));
	return (icol);
}

int		get_color_no(t_set *tmp)
{
	int	icol;

	tmp->tex_x = abs(tmp->tex_x);
	tmp->tex_y = abs(tmp->tex_y);
	if (!tmp->tex_n.h || !tmp->tex_n.w)
		return (0);
	if (tmp->tex_x > tmp->tex_n.w || tmp->tex_y > tmp->tex_n.h)
		return (0);
	icol = (*(int*)(tmp->tex_n.adr + ((tmp->tex_x + (tmp->tex_y * tmp->tex_n.w))
													* (tmp->tex_n.bpp / 8))));
	return (icol);
}

int		get_color_so(t_set *tmp)
{
	int	icol;

	tmp->tex_x = abs(tmp->tex_x);
	tmp->tex_y = abs(tmp->tex_y);
	if (!tmp->tex_s.h || !tmp->tex_s.w)
		return (0);
	if (tmp->tex_x > tmp->tex_s.w || tmp->tex_y > tmp->tex_s.h)
		return (0);
	icol = (*(int*)(tmp->tex_s.adr + ((tmp->tex_x + (tmp->tex_y * tmp->tex_s.w))
													* (tmp->tex_s.bpp / 8))));
	return (icol);
}
