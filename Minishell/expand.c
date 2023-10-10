/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:43:49 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/10 11:16:46 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	exit_status;

int	toogle_quote(char c, char *quote)
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
		if (token->type == DELIMITER)
			remove_quote(token);
		
	}
}