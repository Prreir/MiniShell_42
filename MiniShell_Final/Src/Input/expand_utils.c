/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:48:54 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/17 10:59:22 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	exit_status;

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