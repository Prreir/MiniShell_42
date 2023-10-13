# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 11:07:58 by lugoncal          #+#    #+#              #
#    Updated: 2023/10/13 11:08:50 by lugoncal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./Libft/libft.a

SRC = main.c utils.c ctrl.c env_creation.c exp_creation.c boom.c \
	input.c input_utils.c input_utils2.c utils2.c env.c exp.c \
	expand.c expand_utils.c parse_execute.c parse_utils.c \
	redirect.c heredoc.c heredoc_utils.c clean.c cmd.c execute.c \
	commands.c path.c signals.c utils3.c echo_cmd.c

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