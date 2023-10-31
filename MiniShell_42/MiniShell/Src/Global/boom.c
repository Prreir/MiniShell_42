/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:03:59 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/24 10:43:57 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	cmd_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		i++;
	while (i > 0)
	{
		free(ptr[i - 1]);
		i--;
	}
	free(ptr);
}

void	boom_cmd(t_data *data)
{
	free(data->input);
	data->input = NULL;
	boom_token(&(data->token), free);
	data->token = NULL;
}

void	boom_token(t_token **token, void (*del)(void *))
{
	t_token	*tmp;
	t_token	*next_node;

	if (!token || !del)
		return ;
	tmp = *token;
	while (tmp != NULL)
	{
		next_node = tmp->next;
		del(tmp->word);
		free(tmp);
		tmp = next_node;
	}
	*token = NULL;
}

void	boom(t_data *data)
{
	if (data->env)
		boom_env(data->env);
	if (data->token)
		boom_token(&(data->token), free);
	if (data->exp)
		boom_exp(data->exp);
	rl_clear_history();
}
