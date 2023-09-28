/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:07:52 by lugoncal          #+#    #+#             */
/*   Updated: 2023/09/28 11:13:56 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	data_init(t_data *data)
{
	data->input = NULL;
	data->env = NULL;
	data->exp = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc > 1 && argv)
		error_msg(NULL, INV_ARGS, -1);
	data_init(&data);
	env_birth(&data, envp); //CHANGE THE SHIT NAME
	exp_creation(&data, envp); //append
	while (1)
	{
		ctrl_signals();
		data.input = readline(PROMPT);
		if (ctrl_d(data.input))
			break;
		if (valid(&data))
			continue;
	}
	return (0);
}
