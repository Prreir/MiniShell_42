/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:43:49 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/12 11:45:55 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	exit_status;

char	*expand_remove(char *word, t_data *data)
{
	char	*new;
	char	*var;
	char	quote;

	new = ft_calloc(1, 1);
	quote = 0;
	while (*word)
	{
		if (toogle_quote(*word, &quote))
		{
			word++;
			continue;
		}
		if (can_expand(word, &quote))
		{
			var = find_var(word + 1);
			new = append_var(new, var, data);
			word += 1 + ft_strlen(var);
			free(var);
			continue;
		}
		new = append_char(new, *word);
		word++;
	}
	return (new);
}

int	toogle_quote(const char c, char *quote)
{
	if (is_quote(c))
	{
		if (*quote == c)
		{
			*quote = 0;
			return (1);
		}
		if (*quote == 0)
		{
			*quote = c;
			return (1);
		}
	}
	return (0);
}

void	remove_quote(t_token *token)
{
	char	*old;
	char	*new;
	char	quote;

	old = token->word;
	new = ft_calloc(1, 1);
	quote = 0;
	while (*old)
	{
		if (toogle_quote(*old, &quote))
		{
			old++;
			continue;
		}
		new = append_char(new, *old);
		old++;
	}
	free(token->word);
	token->word = new;
}

void	expand(t_data *data)
{
	t_token *token;
	char    *tmp;

	token = data->token;
	while (token)
	{
		if (token->type == HEREDOC_DELIMITER)
			remove_quote(token);
		else
		{
			til_expand(token, data);
			tmp = expand_remove(token->word, data);
			free(token->word);
			token->word = tmp;
		}
		token = token->next;
	}
}