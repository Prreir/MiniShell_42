/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:07:21 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/17 11:08:38 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	exit_status;

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