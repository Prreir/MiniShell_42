/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:37:32 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/03 12:06:32 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	exit_status;

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
