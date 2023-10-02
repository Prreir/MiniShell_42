/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:08:03 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/01 10:22:07 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "Libft/libft.h"
# include "Libft/get_next_line.h"
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

# define INV_ARGS "Minishell: No support for command-line arguments"

# define RED "\033[38;5;160mMi\033[0m\33[38;5;166mni\033[0m\033[38;5;172mSh\033[0m\033[38;5;178mel\033[0m\033[38;5;184ml$ \033[0m"
# define BLUE "\033[38;5;20mMi\033[0m\33[38;5;26mni\033[0m\033[38;5;32mSh\033[0m\033[38;5;38mel\033[0m\033[38;5;44ml$ \033[0m"

typedef	enum e_type{
	WORD,
	PIPE,
	IN,
	OUT,
	APPEND,
	FILES,
	HEREDOC,
	DELIMITER,
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
}   t_data;

//input.c
int 	process(t_data *data, char *input);
int		input_v(t_data *data);

//boom.c
void	boom_env(t_env *env);
void	boom_input(t_data *data);
void    boom(t_data *data);

//exp_creation.c
t_exp *ft_new_exp(char *vexp_name, char *vexp_value);
t_exp	*ft_last_exp(t_exp *exp);
void ft_exp_to_the_back(t_exp **exp, t_exp *new);
void	exp_creation(t_data *data, char **env);

//env_creation.c
t_env	*new_env(char *v_name, char *v_value);
t_env	*last_env(t_env *env);
void	env_to_the_back(t_env **env, t_env *new);
void	env_creation(t_data *data, char **env);

//ctrl.c
int		ctrl_d (char *input);
void	ctrl_c(int sig);
void	ctrl_signals(void);

//utils.c
int		step_next(char *input);
int		is_quote(char c);
int		is_special(char c);
int		is_space(char c);
void    error_msg(t_data *data, char *msg, int status);

//main.c
void	data_init(t_data *data);
void	wait_for_child_processes(t_data *data);

#endif