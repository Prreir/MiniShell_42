# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 13:28:09 by lugoncal          #+#    #+#              #
#    Updated: 2023/10/25 11:34:28 by lugoncal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_END		=	\e[0m
_BOLD		=	\e[1m
_UNDER		=	\e[4m
_REV		=	\e[7m

_RED		=	\e[02;31m
_GREEN		=	\e[00;32m
_ORANGE		=	\e[02;91m

_GONE		=	\e[2K\r

NAME	:=	minishell
CC	:=	cc
CFLAGS	:=	-Wall -Werror -Wextra -g
DEPS	:=	-lreadline -lXext -lX11 -lm

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
INPUT_DIR	:=	Input/
PARSE_DIR	:=	Parse/
EXECUTE_DIR	:=	Execute/
COMMANDS_DIR	:=	Commands/

GLOBAL	:=	utils.c \
			boom.c \
			utils_2.c \
			utils_3.c \
			utils_4.c

ENV	:=	env.c \
		env_2.c

EXP	:=	exp.c \
		exp_2.c

SIGNAL	:=	signals.c \
			signals_exec.c

INPUT	:=	input.c \
			input_utils.c \
			tokens.c \
			expand.c \
			expand_utils.c \

PARSE	:=	parse.c \
			parse_utils.c \
			cmd.c \
			redirect.c \
			heredoc.c \
			heredoc_signals.c


EXECUTE	:=	execute.c \
				path.c

COMMANDS	:=	commands.c \
				cmd_echo.c \
				cmd_cd.c \
				cmd_pwd.c \
				cmd_export.c \
				cmd_unset.c \
				cmd_exit.c
				
				

GLOBAL_SRC	:=	$(addprefix $(GLOBAL_DIR), $(GLOBAL))
ENV_SRC	:=	$(addprefix $(ENV_DIR), $(ENV))
EXP_SRC	:=	$(addprefix $(EXP_DIR), $(EXP))
SIGNAL_SRC	:=	$(addprefix $(SIGNAL_DIR), $(SIGNAL))
INPUT_SRC	:=	$(addprefix $(INPUT_DIR), $(INPUT))
PARSE_SRC	:=	$(addprefix $(PARSE_DIR), $(PARSE))
EXECUTE_SRC	:=	$(addprefix $(EXECUTE_DIR), $(EXECUTE))
COMMANDS_SRC	:=	$(addprefix $(COMMANDS_DIR), $(COMMANDS))

SRC	:=	$(GLOBAL_SRC) \
		$(ENV_SRC) \
		$(EXP_SRC) \
		$(SIGNAL_SRC) \
		$(INPUT_SRC) \
		$(PARSE_SRC) \
		$(EXECUTE_SRC) \
		$(COMMANDS_SRC) \
		main.c

SOURCES	:=	$(addprefix $(SRC_DIR), $(SRC))
OBJS	:=	$(SRC:.c=.o)
OBJ :=	$(addprefix $(OBJ_DIR), $(OBJS))

all:	$(LIB) $(NAME)

$(LIB):
	@printf "$(_GONE)$(_ORANGE) Making LIBFT... $(_END)\n"
	@make -sC $(LIB_PATH)
	@printf "$(_GONE)$(_ORANGE) LIBFT Created. $(_END)\n"
	@printf "$(_GONE)$(_ORANGE) ============================================ $(_END)\n"

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
	@mkdir -p $@/Input
	@mkdir -p $@/Parse
	@mkdir -p $@/Execute
	@mkdir -p $@/Commands

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