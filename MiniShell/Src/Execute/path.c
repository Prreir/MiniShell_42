/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:40:26 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/17 14:23:48 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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
	int		i;

	i = 0;
	all_path = ft_split(path, ':');
	while (all_path && all_path[i])
	{
		cmd_path = prepend_path(all_path[i], cmd);
		if (executable(cmd_path))
			break ;
		free(cmd_path);
		cmd_path = NULL;
		i++;
	}
	cmd_free(all_path);
	return (cmd_path);
}

int	executable(char *cmd)
{
	if (!access(cmd, F_OK))
		return (0);
	return (1);
}

int	path_defined(char **path_v, t_data *data)
{
	t_env	*path;

	path = search_env("PATH", data);
	if (!path)
	{
		print_error("no such file or directory.", 127);
		return (0);
	}
	*path_v = path->v_value;
	return (0);
}
