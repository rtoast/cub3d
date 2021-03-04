/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:58:05 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/03 18:18:28 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "fcntl.h"
# include "errno.h"
# include "math.h"
# include "stdio.h" //убрать

typedef struct	s_set
{
	//char		*no;
	//char		*so;
	//char		*we;
	//char		*ea;
	int			rx;
	int			ry;
	//int			fr;
	//int			fg;
	//int			fb;
	//int			cr;
	//int			cg;
	//int			cb;
}				t_set;

int	pars_R(char *line, t_set *tmp);

#endif