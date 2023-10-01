/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:38:56 by lugoncal          #+#    #+#             */
/*   Updated: 2023/09/28 15:30:42 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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

int	is_special(char c)
{
	if (c == '>' || c == '<' || c == '|')
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

void	error_msg(t_data *data, char *msg, int status)
{
	if (data)
		boom(data);
	printf("%s\n", msg);
	exit(status);
}
