/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:00:12 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/24 10:33:02 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int		g_exit_status;

void	handle_exit_with_two_args(char **cmd, t_data *data)
{
	long long	exit_code;

	if (is_number(cmd[1]))
	{
		boom(data);
		exit_code = (char)ft_atol(cmd[1]);
		cmd_free(cmd);
		exit(exit_code);
	}
	else
	{
		print_error("numeric argument required", 2);
		boom(data);
	}
}

void	exit_cmd(char **cmd, t_data *data)
{
	int	len;

	len = 0;
	if (has_pipe(data))
		return ;
	while (cmd[len])
		len++;
	printf("exit\n");
	if (len > 2)
	{
		print_error("too many arguments", 1);
		return ;
	}
	if (len == 1)
		boom(data);
	if (len == 2)
		handle_exit_with_two_args(cmd, data);
	cmd_free(cmd);
	exit(g_exit_status);
}
