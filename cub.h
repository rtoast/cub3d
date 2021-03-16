/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:58:05 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/16 03:07:05 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include "fcntl.h"
# include "errno.h"
# include "math.h"
# include "stdio.h" //убрать

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line;
	int			end;
}				t_data;

typedef struct	s_player
{
	double		posx;
	double		posy;
	double			dirx;
	double			diry;
}				t_player;

typedef struct	s_set
{
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*s;
	char		*ea;
	char		play;
	int			mapstr;
	int			rx;
	int			ry;
	int			fr;
	int			fg;
	int			fb;
	int			cr;
	int			cg;
	int			cb;
	int			map_w;
	int			map_l;
	int			linemap;
	int			mapbegin;
	int			color_c;
	int			color_f;
	double		planex;
	double		planey;
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	void		*mlx;
	void		*win;
	t_data		data;
	t_player	player;
}				t_set;

int		pars_r(char *line, t_set *tmp);
int		pars_c(char *line, t_set *tmp);
int		pars_f(char *line, t_set *tmp);
int		skip(int i, char *line, int what);
int		pars_no(char *line, t_set *tmp);
int		pars_so(char *line, t_set *tmp);
int		pars_we(char *line, t_set *tmp);
int		pars_s_(char *line, t_set *tmp);
int		pars_ea(char *line, t_set *tmp);
void	array_map(char *str, t_set *tmp, int i);
int		valid_symbol(char symbol);
void	error(char *str);
void	error_system(int i);
int		strsearch(char *line, char *sought);
int		pars_setting(char *line, t_set *tmp);
void	valid_symbol_right(t_set *tmp, int i, int j);
void	valid_symbol_left(t_set *tmp, int i, int j);
void	valid_symbol_bottom(t_set *tmp, int i, int j);
void	valid_symbol_up(t_set *tmp, int i, int j);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	init(t_set *tmp);
void	player_valid(t_set *tmp, int i, int j);
void	filar(t_set *tmp, int x);
int		my_exit(int key);
int		keybord_manager(int key, t_set *tmp);
void	raycasting(t_set *tmp);

#endif