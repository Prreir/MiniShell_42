/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 10:22:26 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/10 12:58:53 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_exp	*new__exp(char *vexp_name, char *vexp_value)
{
	t_exp *new_exp;

	new_exp = malloc(sizeof(t_exp));
	if (!new_exp)
		return (0);
	new_exp->vexp_name = ft_strdup(vexp_name);
	new_exp->vexp_value = ft_strdup(vexp_value);
	new_exp->next = NULL;
	return (new_exp);
}

void add_exp(t_exp **exp, t_exp *new)
{
	t_exp *curr;

	if (*exp == NULL || ft_strcmp((*exp)->vexp_name, new->vexp_name) >= 0)
	{
		new->next = *exp;
		*exp = new;
	}
	else
	{
		curr = *exp;
		while (curr->next != NULL &&
			ft_strcmp(curr->next->vexp_name, new->vexp_name) < 0)
			curr = curr->next;
		new->next = curr->next;
		curr->next = new;
	}
}

void	exp_creation(t_data *data, char **env)
{
	size_t len;
	int i;
	char *vexp_name;
	char *vexp_value;
	t_exp *new_exp;

	i = 0;
	while (env[i])
	{
		if (ft_strchr(env[i], '='))
		{
			len = ft_strchr(env[i], '=') - env[i];
			vexp_name = malloc(len + 1);
			ft_memcpy(vexp_name, env[i], len);
			vexp_name[len] = '\0';
			vexp_value = ft_strdup(ft_strchr(env[i], '=') + 1);
			new_exp = new__exp(vexp_name, vexp_value);
			add_exp(&data->exp, new_exp);
		}
		free(vexp_name);
		free(vexp_value);
		i++;
	}
}