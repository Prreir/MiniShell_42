/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:32:47 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/25 11:57:12 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	valid_command(char **cmd, int *save, t_data *data)
{
	char	*name;
	char	*path;

	if (cmd[0] && (cmd[0][0] == '.' || cmd[0][0] == '/'))
		return (1);
	if (!cmd[0] || (!path_defined(&path, data)))
		return (0);
	if (!executable(cmd[0]))
	{
		name = get_path(cmd[0], path);
		if (!name)
		{
			restore_save(save);
			print_error("minishell: command not found.", 127);
			return (0);
		}
		free(cmd[0]);
		cmd[0] = name;
	}
	return (1);
}

void	exec_cmd(char **cmd, int *save, int *old_in, t_data *data)
{
	int		pid;
	char	**env;

	if (!cmd[0] || !valid_command(cmd, save, data))
		return ;
	pid = fork();
	signals_exec();
	data->last_pid = pid;
	data->processes++;
	if (pid == 0)
	{
		close(save[IN]);
		close(save[OUT]);
		if (*old_in != 0)
			close(*old_in);
		env = array_env(data);
		if (execve(cmd[0], cmd, env) == -1)
			exec_error(env, cmd, data);
	}
}

void	execute(char **cmd, int *save, int *old_in, t_data *data)
{
	int	i;

	i = 0;
	if (commands(cmd))
		exec_commands(&cmd[i], data);
	else
		exec_cmd(&cmd[i], save, old_in, data);
}
