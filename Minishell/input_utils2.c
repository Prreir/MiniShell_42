/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:37:32 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/12 13:36:02 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	exit_status;

void	clean_token(t_token **token, void(*del)(void *))
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

int valid_sequence(t_data *data, char *input)
{
	t_token	*last;

	if (!data->token && *input == '|')
		return (1);
	last = last_token(data->token);
	if (last && is_special(*(last->word)))
	{
		if (is_redirect(*last->word) && (is_redirect(*input) || *input == '|'))
			return (1);
		if (is_redirect(*last->word) && is_redirect(*input))
			return (1);
		if (*input == '|' && *last->word == '|')
			return (1);
	}
	return (0);
}
