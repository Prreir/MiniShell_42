/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:24:41 by lugoncal          #+#    #+#             */
/*   Updated: 2023/11/06 13:07:48 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	g_exit_status;

void	update_oldpwd(t_data *data)
{
	char	newpwd[256];

	getcwd(newpwd, sizeof(newpwd));
	set_env("OLDPWD", get_env("PWD", data), data);
	set_env("PWD", newpwd, data);
}

int	handle_cd(char *path, t_data *data)
{
	g_exit_status = chdir(path);
	if (g_exit_status < 0)
		return (g_exit_status);
	update_oldpwd(data);
	return (g_exit_status);
}

int	go_old_path(char **path, t_data *data)
{
	*path = get_env("OLDPWD", data);
	if (!*path)
	{
		printf("OLDPWD not set\n");
		g_exit_status = 1;
		return (1);
	}
	printf("%s\n", get_env("OLDPWD", data));
	return (0);
}

void	cd_cmd(t_data *data, char **cmd)
{
	char	*path;

	path = cmd[1];
	if (cmd[1] && cmd[2])
	{
		print_error("too many arguments", 1, cmd);
		g_exit_status = 1;
		return ;
	}
	if (path == NULL || *path == '\0')
		path = get_env("HOME", data);
	else if (*path == '-' && *(path + 1) == '-' && *(path + 2) == '\0')
		path = get_env("HOME", data);
	else if (*path == '-' && *(path + 1) == '\0')
	{
		if (go_old_path(&path, data))
			return ;
	}
	if (handle_cd(path, data) < 0)
	{
		g_exit_status = 1;
		perror("cd");
	}
}
