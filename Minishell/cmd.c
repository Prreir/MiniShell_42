/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:43:31 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/13 10:39:50 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int  exit_status;

char 	**fill_cmd(t_token *token, t_token *cur, char **cmd)
{
	int	i;

	i = 0;
	while (token != cur)
	{
		if (token->type == WORD)
		{
			cmd[i] = ft_strdup(token->word);
			i++;
		}
		token = token->next;
	}
	return (cmd);
}

int	cmd_size(t_token *token, t_token *cur)
{
	int	i;

	i = 0;
	while (token != cur)
	{
		if (token->type == WORD)
			i++;
		token = token->next;
	}
	return (i);
}

char	**cmd_create(t_token *token, t_token *cur)
{
	char	**cmd;
	int	size;

	size = cmd_size(token, cur);
	cmd = (char **)malloc((size + 1) * sizeof(char *));
	cmd[size] = NULL;
	cmd = fill_cmd(token, cur, cmd);
	return (cmd);
}