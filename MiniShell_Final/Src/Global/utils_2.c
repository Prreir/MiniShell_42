/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:13:18 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/17 10:17:14 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	pipe_pedent(t_data *data)
{
	t_token	*last;

	last = last_token(data->token);
	if (last && *(last->word) == '|')
		return (1);
	return (0);
};

int	step_next(char *input)
{
	int	step;

	step = 1;
	while (input[step])
	{
		if (input[step] == input[0])
			return (step);
		step++;
	}
	return (-1);
}

int	is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

int	is_redirect(char c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}