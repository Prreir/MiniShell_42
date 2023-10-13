/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:21:59 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/13 16:19:14 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <stdbool.h>
# include <errno.h>

/* -------------------------------------------------------------------------- */
/*                                   Defines                                  */
/* -------------------------------------------------------------------------- */

# define INV_ARGS "Minishell: No support for command-line arguments"

# define RED "\033[38;5;160mMi\033[0m\33[38;5;166mni\033[0m\033[38;5;172mSh\033[0m\033[38;5;178mel\033[0m\033[38;5;184ml$ \033[0m"
# define BLUE "\033[38;5;20mMi\033[0m\33[38;5;26mni\033[0m\033[38;5;32mSh\033[0m\033[38;5;38mel\033[0m\033[38;5;44ml$ \033[0m"

# define EXIT_CTRL_C 130
# define EXIT_SYNTAX_ERROR 2

# define IN 0
# define OUT 1

# define HEREDOC_FILE ".heredoc"

/* -------------------------------------------------------------------------- */
/*                                   Structs                                  */
/* -------------------------------------------------------------------------- */

typedef	enum e_type{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_FILES,
	HEREDOC,
	HEREDOC_DELIMITER,
}	t_type;

typedef	struct s_token{
	t_type	type;
	char	*word;
	struct s_token *next;
	struct s_token *prev;
}	t_token;

typedef struct s_exp
{
	char			*vexp_name;
	char			*vexp_value;
	struct s_exp	*next;
}					t_exp;

typedef	struct s_env{
	char	*v_name;
	char	*v_value;
	struct s_env	*next;
}	t_env;

typedef struct s_data{
	char	*input;
	t_env	*env;
	t_exp	*exp;
	t_token	*token;
	int		last_pid;
	int		processes;
}   t_data;

/* -------------------------------------------------------------------------- */
/*                                 Prototypes                                 */
/* -------------------------------------------------------------------------- */

//signals.c
int		ctrl_d (char *input);
void	ctrl_c(int sig);
void	signals_ctrl(void);

//boom.c
void	boom_cmd(t_data *data);
void	boom_token(t_token **token, void(*del)(void *));
void	boom(t_data *data);

//exp.c
void	boom_exp(t_exp *exp);
t_exp	*new__exp(char *vexp_name, char *vexp_value);
void	add_exp(t_exp **exp, t_exp *new);
void	exp_create(t_data *data, char **exp);

//env.c
void    boom_env(t_env *env);
t_env	*new_env(char *v_name, char *v_value);
t_env	*last_env(t_env *env);
void	env_to_the_back(t_env **env, t_env *new);
void	env_create(t_data *data, char **env);

//utils.c
int		ft_strcmp(char *s1, char *s2);
void	print_error(char *msg, int error);

//main.c
void	init(t_data *data);

#endif