/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:18:52 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/23 18:18:46 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

int		get_color_spr(t_set *tmp)
{
	int	icol;

	tmp->spr_t.texx = abs(tmp->spr_t.texx);
	tmp->spr_t.texy = abs(tmp->spr_t.texy);
	if (!tmp->tex_sp.h || !tmp->tex_sp.w)
		return (0);
	if (tmp->spr_t.texx > tmp->tex_sp.w || tmp->spr_t.texy > tmp->tex_sp.h)
		return (0);
	icol = (*(int*)(tmp->tex_sp.adr + ((tmp->spr_t.texx +
			(tmp->spr_t.texy * tmp->tex_sp.w)) * (tmp->tex_sp.bpp / 8))));
	return (icol);
}
