# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/07 17:20:27 by kshanti           #+#    #+#              #
#    Updated: 2021/03/13 17:44:00 by rtoast           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

HEAD = ./cub.h
GNL = ./get_next_line/

CFLAGS = -Wall -Wextra -Werror

C_FILE =	$(GNL)get_next_line.c $(GNL)get_next_line_utils.c\
			main.c parser.c parser2.c parser3.c array_map.c\
			additionally.c valid_symbol_map.c

O_FILE = $(C_FILE:.c=.o)

all:
	$(MAKE) $(NAME) -j 4

$(NAME): $(O_FILE)
	$(MAKE) -C ./libft all
	gcc $(O_FILE) ./libft/libft.a -o $(NAME)

%.o: %.c $(HEAD)
	gcc -c $(СFLAGS) $< -o $@

clean:
	@rm -f $(O_FILE)
	$(MAKE) -C ./libft clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re