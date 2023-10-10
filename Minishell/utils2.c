/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:56:20 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/10 11:16:12 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"shell.h"

extern int	exit_status;

int	pipe_pedent(t_data *data)
{
	t_token	*last;

	last = last_token(data->token);
	if (last && *(last->word) == '|')
		return (1);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*get_char(char *input)
{
	if (*input == '|')
		return ("|");
	if (*input == '>')
	{
		if (*(input + 1) == '>')
			return (">>");
		return (">");
	}
	if (*input == '<')
	{
		if (*(input + 1) == '<')
			return ("<<");
		return ("<");
	}
	return ("");
}

int	is_redirect(char c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}