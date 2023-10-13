/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:34:44 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/12 11:46:30 by lugoncal         ###   ########.fr       */
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
	if (ft_strcmp(last->word, "<") == 0 || ft_strcmp(last->word, "<<") == 0 || ft_strcmp(last->word, ">") == 0 || ft_strcmp(last->word, ">>") == 0)
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

char	*special_token(t_data *data, char *input)
{
	if (valid_sequence(data, input))
	{
		ft_putstr_fd("syntax error near unexpected token ", 2);
		ft_putendl_fd(get_char(input), 2);
		exit_status = EXIT_SYNTAX_ERROR;
		return (NULL);
	}
	if (*input == '|')
		return (token_create(input, input, PIPE, data));
	if (*input == '>')
	{
		if (*(input + 1) == '>')
			return (token_create(input, input + 1, REDIR_APPEND, data));
		else
			return (token_create(input, input + 1, REDIR_OUT, data));
	}
	if (*input == '<')
	{
		if (*(input + 1) == '<')
			return (token_create(input, input + 1, HEREDOC, data));
		else
			return (token_create(input, input + 1, REDIR_IN, data));
	}
	return (input);
}

char	*normal_token(t_data *data, char *input)
{
	int	len;
	t_token	*last;	

	len = token_len(input);
	if (len == -1)
		return (NULL);
	last = last_token(data->token);
	if (last && last->type == HEREDOC)
		return (token_create(input, input + len - 1, HEREDOC_DELIMITER, data));
	if (last && (last->type == REDIR_IN || last->type == REDIR_OUT || last->type == REDIR_APPEND))
		return (token_create(input, input + len - 1, REDIR_FILES, data));
	return (token_create(input, input + len - 1, WORD, data));
}

int	process(t_data *data, char *input)
{
	while (*input)
	{
		while (is_space(*input))
			input++;
		if (*input == '\0')
			break;
		if (is_special(*input))
		{
			input = special_token(data, input);
			if (input == NULL)
				return (1);
			continue;
		}
		input = normal_token(data, input);
		if (input == NULL)
			return (1);
	}
	return (valid_last(data));
}

int	input_v(t_data *data)
{
	if (!ft_strlen(data->input))
	{
		free(data->input);
		return (1);
	}
	add_history(data->input);
	if (process(data, data->input))
    {
		exit_status = EXIT_SYNTAX_ERROR;
        boom_input(data);
		return (1);
    }
	expand(data);
	parse_execute(data);
    return (0);
}
