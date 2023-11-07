# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lugoncal <lugoncal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 13:28:09 by lugoncal          #+#    #+#              #
#    Updated: 2023/11/06 13:59:16 by lugoncal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_YELLOW		=	\e[33m
_GREEN		=	\e[32m
_ORANGE		=	\e[31m

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
	@echo "$(_GREEN) ███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     ";
	@echo "$(_GREEN) ████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     ";
	@echo "$(_GREEN) ██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     ";
	@echo "$(_GREEN) ██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     ";
	@echo "$(_GREEN) ██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗";
	@echo "$(_GREEN) ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝";
	@echo "$(_GREEN) =============  Project made by: lugoncal && mmassa-r  =============";
	@make -sC $(LIB_PATH)
	@echo "$(_YELLOW)  Making LIBFT...";
	@echo "$(_YELLOW)  LIBFT Created.";

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIB) $(INCLUDE) $(DEPS)
	@echo "$(_YELLOW)  All files compiled into '$(OBJ_DIR)'.";
	@echo "$(_YELLOW)  Executable '$(NAME)' created.";

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
	@echo "$(_ORANGE)  '"$(OBJ_DIR)"' has been deleted.";

fclean: clean
	@make -sC $(LIB_PATH) fclean
	@rm -f $(NAME)
	@echo "$(_ORANGE)  '"$(NAME)"' has been deleted.";

re: fclean all

valgrind: re
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline_supression ./minishell

.PHONY: all clean fclean re valgrind
