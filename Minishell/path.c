/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 09:44:48 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/13 11:05:29 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	exit_status;

char	*prepend_path(char *envpath, char *cmd)
{
	char	*path;
	char	*f_slash;

	if (cmd[0] == '/' || cmd[0] == '.')
		path = ft_strdup(cmd);
	else
	{
		f_slash = ft_strjoin(envpath, "/");
		path = ft_strjoin(f_slash, cmd);
		free(f_slash);
	}
	return (path);
}

char	*get_path(char *cmd, char *path)
{
	char	**all_path;
	char	*cmd_path;
	int	i;

	i = 0;
	all_path = ft_split(path, ':');
	while (all_path && all_path[i])
	{
		cmd_path = prepend_path(all_path[i], cmd);
		if (executable(cmd_path))
			break;
		free(cmd_path);
		cmd_path = NULL;
		i++;
	}
	cmd_free(all_path);
	return(cmd_path);
}

int	executable(char *cmd)
{
	if (!access(cmd, F_OK))
		return (0);
	return (1);
}