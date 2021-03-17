/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionally_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 02:09:31 by rtoast            #+#    #+#             */
/*   Updated: 2021/03/17 05:18:10 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	valid_name(char *str)
{
	int		numstr;
	int		valid;

	valid = 0;
	numstr = ft_strlen(str);
	if (numstr < 4)
		error("wrong name file");
	if (str[numstr - 1] == 'b')
		valid++;
	if (str[numstr - 2] == 'u')
		valid++;
	if (str[numstr - 3] == 'c')
		valid++;
	if (str[numstr - 4] == '.')
		valid++;
	if (valid < 4)
		error("wrong name file");
}

int		max_r(t_set *tmp)
{
	if (tmp->rx > MAX_WIDTH)
		tmp->rx = MAX_WIDTH;
	if (tmp->ry > MAX_HEIGHT)
		tmp->ry = MAX_HEIGHT;
	return (1);
}