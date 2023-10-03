/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:56:22 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/03 11:31:29 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"shell.h"

extern int	exit_status;

void	token_add_back(t_token **token, t_token *create)
{
	t_token	*tail;

	if (!create)
		return ;
	if (!*token)
	{
		*token = create;
		return ;
	}
	tail = last_token(*token);
	tail->next = create;
	tail->prev = tail;
}

t_token	*new_token(void *word, t_type type)
{
	t_token	*create;

	create = malloc(sizeof(t_token));
	if (!create)
		return (0);
	create->type = type;
	create->word = word;
	create->next = NULL;
	create->prev = NULL;
	return (create);
}

char *token_create(char *input, char *end, t_type type, t_data *data)
{
	t_token *create;
	char *word;

	(void)data;
	if (*end)
	{
		word = ft_substr(input, 0, end - input + 1);
		create = new_token(word, type);
		token_add_back(&data->token, create);
		return (end + 1);
	}
	return (end);
}

t_token	*last_token(t_token *last)
{
	if (last)
	{
		while (last->next != NULL)
			last = last->next;
		return (last);
	}
	return (NULL);
}

int	token_len(char *input)
{
	int len;
	int	step;

	len = 0;
	step = 0;
	while (input[len] && !(is_space(input[len]) || is_special(input[len])))
	{
		if(is_quote(input[len]))
		{
			step = step_next(input);
			if (step == -1)
			{
				printf("error unclosed quote");
				exit_status = EXIT_SYNTAX_ERROR;
				return (-1);
			}
			len = len + step;
		}
		len++;
	}
	return (len);
}