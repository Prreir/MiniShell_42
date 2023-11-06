/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:09:47 by lugoncal          #+#    #+#             */
/*   Updated: 2023/11/06 13:08:43 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	g_exit_status;

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	print_error(char *msg, int error, char **line)
{
	g_exit_status = error;
	if (line == 0)
		printf("%s\n", msg);
	else if (ft_strcmp(line[0], "exit") == 0)
	{
		if (is_number(line[1]))
			printf("%s: %s\n", line[0], msg);
		else
			printf("%s: %s: %s\n", line[0], line[1], msg);
	}
	else if (ft_strcmp(line[0], "exit") != 0)
		printf("%s: %s\n", line[0], msg);
}
