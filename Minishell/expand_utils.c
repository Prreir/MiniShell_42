/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:15:43 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/10 12:15:12 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int exit_status;

char	*append_var(char *word, char *var, t_data *data)
{
	char	*tmp;
	char	*nb;

	if (*var == '?')
	{
		nb = ft_itoa(exit_status);
		tmp = ft_strjoin(word, nb);
		free(word);
		free(nb);
		return (tmp);
	}
	if (get_env(var, data))
	{
		tmp = ft_strjoin(word, get_env(var, data));
		free(word);
		word = tmp;
	}
	return (word);
}

char	*find_var(char *word)
{
	int	i;

	i = 0;
	if (word[i] == '?')
		return (ft_substr(word, 0, 1));
	if (!ft_isalpha(word[i]) && word[i] != '_')
		return (ft_substr(word, 0, 1));
	while (word[i] && (ft_isalnum(word[i]) || word[i] == '_'))
		i++;
	return (ft_substr(word, 0, i));
}

int	can_expand(const char *word, char *quote)
{
	if (*word == '$' && is_quote(*(word + 1)))
	{
		*quote = *(word + 1);
		return (1);
	}
	if (*word == '$' && *(word + 1) && !is_quote(*(word + 1)) && *quote != '\0')
		return (1);
	return (0);
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

char	*append_char(char *str, char c)
{
	char *tmp;

	if (!str || !c)
		return (NULL);
	tmp = malloc(ft_strlen(str) + 2);
	ft_memcpy(tmp, str, ft_strlen(str));
	tmp[ft_strlen(str)] = c;
	tmp[ft_strlen(str) + 1] = '\0';
	free(str);
	return (tmp);
}