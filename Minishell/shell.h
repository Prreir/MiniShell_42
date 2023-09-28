/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:08:03 by lugoncal          #+#    #+#             */
/*   Updated: 2023/09/19 11:53:02 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "Libft/libft.h"
# include "Libft/get_next_line.h"
# include <stdio.h>
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

typedef struct s_env
{
	char			*v_name;
	char			*v_value;
	struct s_env 	*next;
}	t_env;

typedef struct s_data
{
	t_env *env;
}	t_data;

//main.c
void init(t_data *data);

#endif