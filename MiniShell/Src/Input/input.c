/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:40:07 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/25 11:09:46 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	g_exit_status;

char	*normal_token(t_data *data, char *input)
{
	int		len;
	t_token	*last;	

	len = token_len(input);
	if (len == -1)
		return (NULL);
	last = last_token(data->token);
	if (last && last->type == HEREDOC)
		return (token_create(input, input + len - 1, HEREDOC_DELIMITER, data));
	if (last && (last->type == REDIR_IN || last->type == REDIR_OUT || \
				last->type == REDIR_APPEND))
		return (token_create(input, input + len - 1, REDIR_FILES, data));
	return (token_create(input, input + len - 1, WORD, data));
}

char	*special_token(t_data *data, char *input)
{
	if (valid_sequence(data, input))
	{
		ft_putstr_fd("syntax error near unexpected token ", 2);
		ft_putendl_fd(get_char(input), 2);
		g_exit_status = EXIT_SYNTAX_ERROR;
		return (NULL);
	}
	if (*input == '|')
		return (token_create(input, input, PIPE, data));
	if (*input == '>')
	{
		if (*(input + 1) == '>')
			return (token_create(input, input + 1, REDIR_APPEND, data));
		else
			return (token_create(input, input, REDIR_OUT, data));
	}
	if (*input == '<')
	{
		if (*(input + 1) == '<')
			return (token_create(input, input + 1, HEREDOC, data));
		else
			return (token_create(input, input, REDIR_IN, data));
	}
	return (input);
}

int	process(t_data *data, char *input)
{
	while (*input)
	{
		while (is_space(*input))
			input++;
		if (*input == '\0')
			break ;
		if (is_special(*input))
		{
			input = special_token(data, input);
			if (input == NULL)
				return (1);
			continue ;
		}
		input = normal_token(data, input);
		if (input == NULL)
			return (1);
	}
	return (valid_last(data));
}

int	valid_input(t_data *data)
{
	if (!ft_strlen(data->input))
	{
		free(data->input);
		return (1);
	}
	add_history(data->input);
	if (process(data, data->input))
	{
		g_exit_status = EXIT_SYNTAX_ERROR;
		boom_cmd(data);
		return (1);
	}
	expand(data);
	parse_execute(data);
	return (0);
}
