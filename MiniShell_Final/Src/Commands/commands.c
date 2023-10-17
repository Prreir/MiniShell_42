/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:34:41 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/17 13:22:38 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	exec_commands(char **cmd, t_data *data)
{
	(void)data;
	if (ft_strcmp(cmd[0], "echo") == 0)
		echo_cmd(cmd + 1);
	// else if (ft_strcmp(cmd[0], "cd") == 0)
	// 	cd_cmd(data, cmd + 1);
	// else if (ft_strcmp(cmd[0], "pwd") == 0)
	// 	pwd_cmd();
	else if (ft_strcmp(cmd[0], "export") == 0)
	{
		if (cmd[1] == NULL)
			print_exp(data);
	// 	else
	// 		export_cmd(data, cmd + 1);
	}
	// else if (ft_strcmp(cmd[0], "unset") == 0)
	// 	unset_cmd(data, cmd + 1);
	else if (ft_strcmp(cmd[0], "env") == 0)
	{
		if (cmd[1] == NULL)
			print_env(data);
	}
	// else if (ft_strcmp(cmd[0], "exit") == 0)
	// 	exit_cmd(cmd, data);
}

int	commands(char **cmd)
{
	if (!cmd || !*cmd)
		return (0);
	if (ft_strcmp(cmd[0], "echo") == 0)
		return (1);
	if (ft_strcmp(cmd[0], "cd") == 0)
		return (1);
	if (ft_strcmp(cmd[0], "pwd") == 0)
		return (1);
	if (ft_strcmp(cmd[0], "export") == 0)
		return (1);
	if (ft_strcmp(cmd[0], "unset") == 0)
		return (1);
	if (ft_strcmp(cmd[0], "env") == 0)
		return (1);
	if (ft_strcmp(cmd[0], "exit") == 0)
	{
		return (1);
	}
	return (0);
}