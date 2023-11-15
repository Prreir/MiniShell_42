/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:45:45 by lugoncal          #+#    #+#             */
/*   Updated: 2023/11/14 10:26:02 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	close_last_input(int old_in)
{
	if (old_in != 0)
		close(old_in);
}

void	exec_error(char **env, char **cmd, t_data *data)
{
	printf("command not found\n");
	cmd_free(env);
	cmd_free(cmd);
	boom(data);
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
