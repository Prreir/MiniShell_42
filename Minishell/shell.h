/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:08:03 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/13 11:04:31 by lugoncal         ###   ########.fr       */
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
# include <errno.h>

# define INV_ARGS "Minishell: No support for command-line arguments"

# define RED "\033[38;5;160mMi\033[0m\33[38;5;166mni\033[0m\033[38;5;172mSh\033[0m\033[38;5;178mel\033[0m\033[38;5;184ml$ \033[0m"
# define BLUE "\033[38;5;20mMi\033[0m\33[38;5;26mni\033[0m\033[38;5;32mSh\033[0m\033[38;5;38mel\033[0m\033[38;5;44ml$ \033[0m"

# define EXIT_CTRL_C 130
# define EXIT_SYNTAX_ERROR 2

# define IN 0
# define OUT 1

# define HEREDOC_FILE ".heredoc"

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

//echo_cmd.c
void	print_word(char **word, int i, int flag);
void	echo_cmd(char **cmd);

//utils3.c
void	close_last_input(int old_in);
void	exec_error(char **env, char **cmd, t_data *data);
char	*join_three(char *one, char *two, char *three);

//signals.c
void	handle_exec_ctrl_c(int signal);
void	handle_exec_ctrl_bslash(int signal);
void	register_signal(void);

//path.c
char	*prepend_path(char *envpath, char *cmd);
char	*get_path(char *cmd, char *path);
int		executable(char *cmd);

//commands.c
void	exec_commands(char **cmd, t_data *data);
int		commands(char **cmd);

//execute.c
void	execute(char **cmd, int *save, int *old_in, t_data *data);

//cmd.c
char 	**fill_cmd(t_token *token, t_token *cur, char **cmd);
int		cmd_size(t_token *token, t_token *cur);
char	**cmd_create(t_token *token, t_token *cur);

//clean.c
void	delexp(t_exp *tmp);
void	clean_exp(t_exp *exp);
void	delenv(t_env *tmp);
void	clean_env(t_env *env);
void	clean_all(t_data *data);

//heredoc_utils.c
void	wait_and_update_main_signals(int pid, int *status);
void	handle_heredoc_ctrl_c(int signal);

//heredoc.c
void	heredoc_input(int tmp, char *file, t_data *data);
int		tmp_create(void);
int		heredoc(char *file, int *save, t_data *data);

//redirect.c
int		redirect_out(char *file, int flags);
int		make_redirect(char *word, char *file, int *save, t_data *data);
int		check_redirect(t_token *token, t_token *cur, int *save, t_data *data);

//parse_utils.c
void	file_heap(char *file, char *delimiter);
void	restore_save(int *save);
void	start_save(int *save);

//parse_execute.c
void	parse_command(t_token *token, t_token *cur, int *old_in, t_data *data);
void	parse(t_token *token, int *old_in, t_data *data);
void	parse_execute(t_data *data);

//expand_utils.c
char	*append_var(char *word, char *var, t_data *data);
char	*find_var(char *word);
int		can_expand(const char *word, char *quote);
void    til_expand(t_token *token, t_data *data);
char	*append_char(char *str, char c);

//expand.c
int		toogle_quote(const char c, char *quote);
void	remove_quote(t_token *token);
void	expand(t_data *data);

//env.c
char	**array_env(t_data *data);
char	*get_env(char *name, t_data *data);
int		set_env(char *name, char *new_value, t_data *data);
t_env	*search_env(char *name, t_data *data);
void	print_env(t_data *data);

//exp.c
char	*get_exp(char *name, t_data *data);
int		set_exp(char *name, char *new_value, t_data *data);
t_exp	*search_exp(char *name, t_data *data);
void	print_exp(t_data *data);

//utils2.c
void	print_error(char *msg, int error);
int		pipe_pedent(t_data *data);
int		ft_strcmp(char *s1, char *s2);
char	*get_char(char *input);
int		is_redirect(char c);

//input_utils2.c
void	clean_token(t_token **token, void(*del)(void *));
int		valid_sequence(t_data *data, char *input);

//input_utils.c
void	token_add_back(t_token **token, t_token *create);
t_token	*new_token(void *word, t_type type);
char	*token_create(char *input, char *end, t_type type, t_data *data);
t_token	*last_token(t_token *last);
int		token_len(char *input);

//input.c
char	*special_token(t_data *data, char *input);
char	*normal_token(t_data *data, char *input);
int 	process(t_data *data, char *input);
int		input_v(t_data *data);

//boom.c
void	cmd_free(char **ptr);
void	boom_env(t_env *env);
void	boom_input(t_data *data);
void    boom(t_data *data);

//exp_creation.c
t_exp	*new__exp(char *vexp_name, char *vexp_value);
t_exp	*last_exp(t_exp *exp);
void	add_exp(t_exp **exp, t_exp *new);
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
void    error_msg(t_data *data, char *msg);

//main.c
void	wait_for_child_processes(t_data *data);
void	data_init(t_data *data);

#endif