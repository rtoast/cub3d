/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionally_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 02:09:31 by rtoast            #+#    #+#             */
/*   Updated: 2021/03/23 19:01:01 by rtoast           ###   ########.fr       */
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
	if (valid != 4)
		error("wrong name file");
}

void	valid_save(char *str, t_set *tmp)
{
	int		valid;
	int		i;
	int		numstr;

	valid = 0;
	i = 0;
	numstr = ft_strlen(str);
	if (numstr != 6)
		error("wrong save");
	if (str[i] == '-')
		valid++;
	if (str[++i] == '-')
		valid++;
	if (str[++i] == 's')
		valid++;
	if (str[++i] == 'a')
		valid++;
	if (str[++i] == 'v')
		valid++;
	if (str[++i] == 'e')
		valid++;
	if (valid != 6)
		error("wrong save");
	tmp->screen = 1;
}

int		max_r(t_set *tmp)
{
	if (tmp->rx > MAX_WIDTH)
		tmp->rx = MAX_WIDTH;
	if (tmp->ry > MAX_HEIGHT)
		tmp->ry = MAX_HEIGHT;
	return (1);
}

void	create_head(t_set *tmp, int fd, int *colnum)
{
	unsigned int	size;
	unsigned char	bmp[54];

	*colnum = (4 - (tmp->rx * 3) % 4) % 4;
	size = 54 + (*colnum + (tmp->rx * 3)) * tmp->ry;
	ft_memset(bmp, (unsigned char)0, 54);
	bmp[0] = 'B';
	bmp[1] = 'M';
	bmp[2] = (unsigned char)size;
	bmp[3] = (unsigned char)(size >> 8);
	bmp[4] = (unsigned char)(size >> 16);
	bmp[5] = (unsigned char)(size >> 24);
	bmp[10] = (unsigned char)54;
	bmp[14] = (unsigned char)40;
	bmp[18] = (unsigned char)(tmp->rx);
	bmp[19] = (unsigned char)(tmp->rx >> 8);
	bmp[20] = (unsigned char)(tmp->rx >> 16);
	bmp[21] = (unsigned char)(tmp->rx >> 24);
	bmp[22] = (unsigned char)(tmp->ry);
	bmp[23] = (unsigned char)(tmp->ry >> 8);
	bmp[24] = (unsigned char)(tmp->ry >> 16);
	bmp[25] = (unsigned char)(tmp->ry >> 24);
	bmp[26] = (unsigned char)1;
	bmp[28] = (unsigned char)24;
	write(fd, bmp, 54);
}

void	screen(t_set *tmp)
{
	int				fd;
	int				i;
	int				colnum;
	unsigned char	bmp[3];

	bmp[0] = (unsigned char)0;
	bmp[1] = (unsigned char)0;
	bmp[2] = (unsigned char)0;
	fd = open("screen.bmp", O_WRONLY | O_CREAT, S_IRWXU, S_IRWXG);
	create_head(tmp, fd, &colnum);
	while (--tmp->ry >= 0)
	{
		i = -1;
		while (++i < tmp->rx)
			write(fd, &((int *)tmp->data.addr)[tmp->ry
			* tmp->rx + i], 3);
		write(fd, bmp, colnum);
	}
	close(fd);
	exit(0);
}
