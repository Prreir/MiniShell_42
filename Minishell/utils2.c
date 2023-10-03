/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:56:20 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/03 12:04:02 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"shell.h"

extern int	exit_status;

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