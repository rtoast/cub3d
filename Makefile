# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/07 17:20:27 by kshanti           #+#    #+#              #
#    Updated: 2021/03/23 19:47:02 by rtoast           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

HEAD = ./cub.h
GNL = ./get_next_line/

CFLAGS = -Wall -Wextra -Werror
MLX = ./mlx/libmlx.a -framework OpenGL -framework Appkit

C_FILE =	$(GNL)get_next_line.c $(GNL)get_next_line_utils.c\
			main.c parser.c parser2.c parser3.c array_map.c\
			additionally.c valid_symbol_map.c mlx_work.c ray.c\
			key.c texture.c additionally_two.c sprite.c get_color.c\
			ray2.c additionally_3.c

O_FILE = $(C_FILE:.c=.o)

all:
	$(MAKE) $(NAME) -j 4

$(NAME): $(O_FILE)
	$(MAKE) -C ./libft all
	$(MAKE) -C ./mlx all
	gcc $(O_FILE) ./libft/libft.a $(MLX) -o $(NAME)

%.o: %.c $(HEAD)
	gcc -c $(СFLAGS) $< -o $@

clean:
	@rm -f $(O_FILE)
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./mlx clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

norm:
	norminette $(C_FILE)

.PHONY: all clean fclean re norm