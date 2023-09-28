/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:08:03 by lugoncal          #+#    #+#             */
/*   Updated: 2023/09/28 11:44:02 by lugoncal         ###   ########.fr       */
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

# define PROMPT "\033[38;5;20mMi\033[0m\33[38;5;26mni\033[0m\033[38;5;32mSh\033[0m\033[38;5;38mel\033[0m\033[38;5;44ml$ \033[0m"

typedef	struct s_env{
	char	*v_name;
	char	*v_value;
	struct s_env	*next;
}	t_env;

typedef struct s_data{
	char	*input;
	t_env	*env;
}   t_data;

//env_birth.c
t_env *ft_new_env(char *v_name, char *v_value);
t_env	*ft_last_env(t_env *env);
void ft_env_to_the_back(t_env **env, t_env *new);
void	env_birth(t_data *data, char **env);

//ctrl.c
int		ctrl_d (char *input);
void	ctrl_c(int sig);
void	ctrl_signals(void);

//utils.c
int	valid(t_data *data);
void    boom(t_data *data);
void    error_msg(t_data *data, char *msg, int status);

//main.c
void	data_init(t_data *data);

#endif