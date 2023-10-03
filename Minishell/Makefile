# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 11:07:58 by lugoncal          #+#    #+#              #
#    Updated: 2023/10/01 10:25:25 by lugoncal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./Libft/libft.a

SRC = main.c utils.c ctrl.c env_creation.c exp_creation.c env.c exp.c boom.c input.c

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(LIBFT):
			$(MAKE) -C ./Libft

$(NAME):	$(OBJ) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -lreadline -o minishell

clean:
		$(MAKE) clean -C ./Libft
		rm -rf $(OBJ)

fclean:	clean
		$(MAKE) fclean -C ./Libft
		rm -rf $(NAME)

re:	fclean all

.SILENT: