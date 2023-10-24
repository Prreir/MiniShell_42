/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:21:59 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/24 10:45:02 by lugoncal         ###   ########.fr       */
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
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>

/* -------------------------------------------------------------------------- */
/*                                   Defines                                  */
/* -------------------------------------------------------------------------- */

# define INV_ARGS "Minishell: No support for command-line arguments"

# define BLUE "\033[38;5;20mMi\033[0m\33[38;5;26mni\033[0m\033[38;5;32mSh\
\033[0m\033[38;5;38mel\033[0m\033[38;5;44ml$ \033[0m"

# define EXIT_CTRL_C 130
# define EXIT_SYNTAX_ERROR 2
# define CODE_CMD_NOT_FOUND 127

# define IN 0
# define OUT 1

# define HEREDOC_FILE ".heredoc"

/* -------------------------------------------------------------------------- */
/*                                   Structs                                  */
/* -------------------------------------------------------------------------- */

typedef enum e_type {
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_FILES,
	HEREDOC,
	HEREDOC_DELIMITER,
}	t_type;

typedef struct s_token {
	t_type			type;
	char			*word;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_exp {
	char			*vexp_name;
	char			*vexp_value;
	struct s_exp	*next;
}					t_exp;

typedef struct s_env {
	char			*v_name;
	char			*v_value;
	struct s_env	*next;
}	t_env;

typedef struct s_data {
	char	*input;
	t_env	*env;
	t_exp	*exp;
	t_token	*token;
	int		last_pid;
	int		processes;
}	t_data;

/* -------------------------------------------------------------------------- */
/*                                 Prototypes                                 */
/* -------------------------------------------------------------------------- */

//utils_4.c
int			is_all_digits(char *str);
int			is_number(char *str);
long long	ft_atol(const char *str);

//cmd_exit.c
void		handle_exit_with_two_args(char **cmd, t_data *data);
void		exit_cmd(char **cmd, t_data *data);

//cmd_unset.c
void		unset_envvariables(t_data *data, char *key);
void		unset_expvariables(t_data *data, char *key);
int			is_valid_key_unset(char *key, char *type);
void		unset_cmd(t_data *data, char **cmd);

//cmd_export.c
void		only_export(t_data *data, char *key);
int			is_valid_key(char *key, char *cmd, char *type);
void		export_single(char *cmd, t_data *data);
void		export_cmd(t_data *data, char **cmd);

//cmd_pwd.c
void		pwd_cmd(void);

//cmd_cd.c
void		update_oldpwd(t_data *data);
int			handle_cd(char *path, t_data *data);
int			go_old_path(char **path, t_data *data);
void		cd_cmd(t_data *data, char **cmd);

//cmd_echo.c
void		print_word(char **word, int i, int flag);
void		echo_cmd(char **cmd);

//exp_2.c
t_exp		*search_exp(char *name, t_data *data);
int			set_exp(char *name, char *new_value, t_data *data);
char		*get_exp(char *name, t_data *data);
void		print_exp(t_data *data);

//heredoc_signals.c
void		wait_and_update_main_signals(int pid, int *status);
void		handle_heredoc_ctrl_c(int signal);

//heredoc.c
void		input_update(void);
void		tmp_clear(void);
void		heredoc_input(int tmp, char *file, t_data *data);
int			tmp_create(void);
int			heredoc(char *file, int *save, t_data *data);

//redirect.c
int			redirect_out(char *file, int flags);
int			make_redirect(char *word, char *file, int *save, t_data *data);
int			check_redirect(t_token *token, t_token *cur, int *save, \
			t_data *data);

//utils_3.c
void		close_last_input(int old_in);
void		exec_error(char **env, char **cmd, t_data *data);
char		*join_three(char *one, char *two, char *three);

//path.c
char		*prepend_path(char *envpath, char *cmd);
char		*get_path(char *cmd, char *path);
int			executable(char *cmd);
int			path_defined(char **path_v, t_data *data);

//commands.c
void		exec_commands(char **cmd, t_data *data);
int			commands(char **cmd);

//execute.c
int			valid_command(char **cmd, int *save, t_data *data);
void		exec_cmd(char **cmd, int *save, int *old_in, t_data *data);
void		execute(char **cmd, int *save, int *old_in, t_data *data);

//cmd.c
char		**fill_cmd(t_token *token, t_token *cur, char **cmd);
int			cmd_size(t_token *token, t_token *cur);
char		**cmd_create(t_token *token, t_token *cur);

//parse_utils.c
void		file_heap(char *file, char *delimiter);
void		restore_save(int *save);
void		pipe_create(t_token *cur, int *old_in);
void		start_save(int	*save);

//parse.c
void		parse_command(t_token *token, t_token *cur, int *old_in, \
			t_data *data);
void		parse(t_token *token, int *old_in, t_data *data);
void		parse_execute(t_data *data);

//env_2.c
int			set_env(char *key, char *newvalue, t_data *data);
void		print_env(t_data *data);
char		**array_env(t_data *data);
t_env		*search_env(char *name, t_data *data);
char		*get_env(char *name, t_data *data);

//exapnd_utils.c
char		*append_var(char *word, char *var, t_data *data);
char		*find_var(char *word);
int			can_expand(const char *word, char *quote);
char		*append_char(char *str, char c);
int			toogle_quote(const char c, char *quote);

//expand.c
char		*expand_remove(char *word, t_data *data);
void		til_expand(t_token *token, t_data *data);
void		remove_quote(t_token *token);
void		expand(t_data *data);

//utils_2.c
int			has_pipe(t_data *data);
int			pipe_pedent(t_data *data);
int			step_next(char *input);
int			is_quote(char c);
int			is_redirect(char c);

//tokens.c
int			token_len(char *input);
void		token_add_back(t_token **token, t_token *create);
t_token		*new_token(void *word, t_type type);
char		*token_create(char *input, char *end, t_type type, t_data *data);
t_token		*last_token(t_token *last);

//input_utils.c
int			valid_last(t_data *data);
int			valid_sequence(t_data *data, char *input);

//input.c
char		*normal_token(t_data *data, char *input);
char		*special_token(t_data *data, char *input);
int			process(t_data *data, char *input);
int			valid_input(t_data *data);

//signals.c
int			ctrl_d(char *input);
void		ctrl_c(int sig);
void		signals_ctrl(void);

//boom.c
void		cmd_free(char **ptr);
void		boom_cmd(t_data *data);
void		boom_token(t_token **token, void (*del)(void *));
void		boom(t_data *data);

//exp.c
void		boom_exp(t_exp *exp);
t_exp		*new__exp(char *vexp_name, char *vexp_value);
void		add_exp(t_exp **exp, t_exp *new);
void		exp_create(t_data *data, char **exp);

//env.c
void		boom_env(t_env *env);
t_env		*new_env(char *v_name, char *v_value);
t_env		*last_env(t_env *env);
void		env_to_the_back(t_env **env, t_env *new);
void		env_create(t_data *data, char **env);

//utils.c
char		*get_char(char *input);
int			is_special(char c);
int			is_space(char c);
int			ft_strcmp(char *s1, char *s2);
void		print_error(char *msg, int error);

//main.c
void		init(t_data *data);

#endif