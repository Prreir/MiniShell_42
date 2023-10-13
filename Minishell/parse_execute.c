/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:51:50 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/13 10:25:21 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	exit_status;

void	pipe_create(t_token *cur, int *old_in)
{
	int	new_pipe[2];

	dup2(*old_in, STDIN_FILENO);
	if (!old_in != STDIN_FILENO)
		close (*old_in);
	if (!cur)
		return ;
	pipe(new_pipe);
	dup2(new_pipe[OUT], STDOUT_FILENO);
	close(new_pipe[OUT]);
	*old_in = new_pipe[IN];
}

void	parse_command(t_token *token, t_token *cur, int *old_in, t_data *data)
{
	int	save[2];
	char 	**cmd;

	start_save(save);
	pipe_create(cur, old_in);
	if (check_redirect(token, cur, save, data) == 0)
	{
		cmd = cmd_create(token, cur);
		execute(cmd, save, old_in, data);
		cmd_free(cmd);
	}
	restore_save(save);
}

void	parse(t_token *token, int *old_in, t_data *data)
{
	t_token	*cur;

	cur = token;
	while (cur)
	{
		if (cur->type == PIPE)
		{
			parse_command(token, cur, old_in, data);
			token = cur->next;
			parse(token, old_in, data);
		}
		cur = cur->next;
	}
	if (!cur)
		parse_command(token, cur, old_in, data);
}

void	parse_execute(t_data *data)
{
	int	old_in;

	if (!data->token)
		return ;
	old_in = STDIN_FILENO;
	parse(data->token, &old_in, data);
	close_last_input(old_in);
}