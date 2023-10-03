/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:07:52 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/03 13:06:44 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		exit_status;

void	wait_for_child_processes(t_data *data)
{
	int 	status;

	if (waitpid(data->last_pid, &status, 0) != -1)
	{
		data->processes--;
		if (WIFEXITED(status) != 0)
			exit_status = WEXITSTATUS(status);
		data->last_pid = 0;
	}
	while (data->processes)
	{
		wait(0);
		data->processes--;
	}
}

void	data_init(t_data *data)
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

	if (argc > 1 && argv)
	{
		exit_status = EXIT_FAILURE;
		error_msg(NULL, INV_ARGS);
	}
	data_init(&data);
	env_creation(&data, envp);
	exp_creation(&data, envp);
	while (1)
	{
		ctrl_signals();
		data.input = readline(BLUE);
		if (ctrl_d(data.input))
			break;
		if (input_v(&data))
			continue;
		wait_for_child_processes(&data);
		boom_input(&data);
	}
	boom(&data);
	return (EXIT_SUCCESS);
}
