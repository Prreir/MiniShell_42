/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:57:55 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/17 10:05:52 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	exit_status;

int	valid_last(t_data *data)
{
	t_token	*last;

	last = last_token(data->token);
	if (!last)
		return (1);
	if (ft_strcmp(last->word, "<") == 0 || ft_strcmp(last->word, "<<") == 0 || \
		ft_strcmp(last->word, ">") == 0 || ft_strcmp(last->word, ">>") == 0)
	{
		ft_putendl_fd("syntax error near unexpected token `newline'", 2);
		exit_status = EXIT_SYNTAX_ERROR;
		return (1);
	}
	if (pipe_pedent(data))
	{
		ft_putendl_fd("error: pending pipe", 2);
		exit_status = EXIT_SYNTAX_ERROR;
		return (1);
	}
	return (0);
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