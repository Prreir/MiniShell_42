/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:08:20 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/13 10:24:11 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	exit_status;

void	close_last_input(int old_in)
{
	if (old_in != 0)
		close(old_in);
}

void	exec_error(char **env, char **cmd, t_data *data)
{
	printf("minishell: command not found\n");
	cmd_free(env);
	cmd_free(cmd);
	clean_all(data);
	exit(127);
}

char	*join_three(char *one, char *two, char *three)
{
	char	*tmp;
	char	*final;

	if (!(one && two && three))
		return (NULL);
	tmp = ft_strjoin(one, two);
	final = ft_strjoin(tmp, three);
	free(tmp);
	return (final);
}