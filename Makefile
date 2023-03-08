# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 15:32:58 by mabaron-          #+#    #+#              #
#    Updated: 2023/03/06 10:44:17 by mabaron-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c ft_read_and_stash_map.c ft_valid_map.c ft_str_2d.c error.c \
	ft_one_rule.c ft_valid_path.c ft_image.c ft_move.c ft_check.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx
RM = rm -f

LIBFT = libft.a
LIBFTD = libft/

all : $(LIBFTD)$(LIBFT) $(NAME)

$(LIBFTD)$(LIBFT):
	$(MAKE) -C $(LIBFTD)
	$(MAKE) -C $(LIBFTD) bonus

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFTD)$(LIBFT) -fsanitize=address -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@$(RM) $(OBJ) $(NAME)
fclean: clean
	@$(RM) $(NAME)
	$(MAKE) -C $(LIBFTD) fclean
re: fclean all