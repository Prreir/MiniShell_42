# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 13:28:09 by lugoncal          #+#    #+#              #
#    Updated: 2023/10/13 16:21:03 by lugoncal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_END		=	\e[0m
_BOLD		=	\e[1m
_UNDER		=	\e[4m
_REV		=	\e[7m


_GREY		=	\e[1;30m
_RED		=	\e[1;31m
_GREEN		=	\e[1;32m
_YELLOW		=	\e[1;33m
_BLUE		=	\e[1;34m
_PURPLE		=	\e[1;35m
_CYAN		=	\e[1;36m
_WHITE		=	\e[1;37m


_GONE		=	\e[2K\r

NAME	:=	minishell
CC	:=	cc
CFLAGS	:=	-Wall -Werror -Wextra -g
DEPS	:=	-lreadline #-lXext -lX11 -lm

INCLUDE	=	-I ./Include/\
			-I ./Libft/

LIB_PATH	=	./Libft/
LIB_NAME	=	libft.a
LIB	=	$(LIB_PATH)$(LIB_NAME)

SRC_DIR	:=	./Src/
OBJ_DIR	:=	./Obj/

GLOBAL_DIR	:=	Global/
ENV_DIR	:=	Environment/
EXP_DIR	:=	Export/
SIGNAL_DIR	:=	Signals/

GLOBAL	:=	utils.c \
			boom.c \

ENV	:=	env.c

EXP	:=	exp.c

SIGNAL	:=	signals.c

GLOBAL_SRC	:=	$(addprefix $(GLOBAL_DIR), $(GLOBAL))
ENV_SRC	:=	$(addprefix $(ENV_DIR), $(ENV))
EXP_SRC	:=	$(addprefix $(EXP_DIR), $(EXP))
SIGNAL_SRC	:=	$(addprefix $(SIGNAL_DIR), $(SIGNAL))

SRC	:=	$(GLOBAL_SRC) \
		$(ENV_SRC) \
		$(EXP_SRC) \
		$(SIGNAL_SRC) \
		main.c

SOURCES	:=	$(addprefix $(SRC_DIR), $(SRC))
OBJS	:=	$(SRC:.c=.o)
OBJ :=	$(addprefix $(OBJ_DIR), $(OBJS))

all:	$(LIB) $(NAME)

$(LIB):
	@printf "$(_GONE)$(_YELLOW) Making LIBFT... $(_END)\n"
	@make -sC $(LIB_PATH)
	@printf "$(_GONE)$(_GREEN) LIBFT Created. $(_END)\n"
	@printf "$(_GONE)$(_BLUE) ============================================ $(_END)\n"

$(NAME):	$(OBJ)
	@printf "\033[2K\r$(_GREEN) All files compiled into '$(OBJ_DIR)'. $(_END)\n"
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIB) $(INCLUDE) $(DEPS)
	@printf "\033[2K\r$(_GREEN) Executable '$(NAME)' created. $(_END)\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJ_DIR):
	@mkdir -p $@
	@mkdir -p $@/Global
	@mkdir -p $@/Environment
	@mkdir -p $@/Export
	@mkdir -p $@/Signals

clean:
	@make -sC $(LIB_PATH) clean
	@rm -rf $(OBJ_DIR)
	@printf "\033[2K\r$(_RED) '"$(OBJ_DIR)"' has been deleted. $(_END)\n"

fclean: clean
	@make -sC $(LIB_PATH) fclean
	@rm -f $(NAME)
	@printf "\033[2K\r$(_RED) '"$(NAME)"' has been deleted. $(_END)\n"

re: fclean all

.PHONY: all clean fclean re