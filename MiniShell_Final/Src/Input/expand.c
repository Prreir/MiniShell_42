/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:45:06 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/17 10:50:11 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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

void	til_expand(t_token *token, t_data *data)
{
	char	*tmp;

	if (token->word[0] == '~')
	{
		if (token->word[1] == '\0' || token->word[1] == '/')
		{
			tmp = ft_strjoin(get_env("HOME", data), token->word + 1);
			free(token->word);
			token->word = tmp;
		}
	}
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
