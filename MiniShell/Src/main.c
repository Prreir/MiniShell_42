/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:07:52 by lugoncal          #+#    #+#             */
/*   Updated: 2023/11/06 13:02:09 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		g_exit_status;

void	wait_for_child_processes(t_data *data)
{
	int	status;

	if (waitpid(data->last_pid, &status, 0) != -1)
	{
		data->processes--;
		if (WIFEXITED(status))
			g_exit_status = WEXITSTATUS(status);
		data->last_pid = 0;
	}
	while (data->processes)
	{
		wait(0);
		data->processes--;
	}
}

void	init(t_data *data)
{
	data->input = NULL;
	data->env = NULL;
	data->exp = NULL;
	data->token = NULL;
	data->last_pid = 0;
	data->processes = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)envp;
	if (argc > 1 && argv)
	{
		print_error(INV_ARGS, EXIT_FAILURE, 0);
		return (EXIT_FAILURE);
	}
	init(&data);
	env_create(&data, envp);
	exp_create(&data, envp);
	while (1)
	{
		signals_ctrl();
		data.input = readline(BLUE);
		if (ctrl_d(data.input))
			break ;
		if (valid_input(&data))
			continue ;
		wait_for_child_processes(&data);
		boom_cmd(&data);
	}
	boom(&data);
	return (EXIT_SUCCESS);
}
