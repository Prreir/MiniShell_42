/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:07:52 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/01 10:24:43 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	data_init(t_data *data)
{
	data->input = NULL;
	data->env = NULL;
	data->exp = NULL;
	data->token = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc > 1 && argv)
		error_msg(NULL, INV_ARGS, -1);
	data_init(&data);
	env_birth(&data, envp);
	exp_creation(&data, envp);
	while (1)
	{
		ctrl_signals();
		data.input = readline(BLUE);
		if (ctrl_d(data.input))
			break;
		if (input_v(&data))
			continue;
		boom_input(&data);
	}
	boom(&data);
	return (0);
}
