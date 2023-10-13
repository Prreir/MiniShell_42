/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:51:06 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/13 16:06:42 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	boom_exp(t_exp *exp)
{
    t_exp	*tmp;

    while (exp)
	{
		tmp = exp;
		exp = exp->next;
		if (!tmp)
			break;
		free(tmp->vexp_name);
		free(tmp->vexp_value);
		free(tmp);
	}
}

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

void	add_exp(t_exp **exp, t_exp *new)
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

void	exp_create(t_data *data, char **exp)
{
	size_t len;
	int i;
	char *vexp_name;
	char *vexp_value;
	t_exp *new_exp;

	i = 0;
	while (exp[i])
	{
		if (ft_strchr(exp[i], '='))
		{
			len = ft_strchr(exp[i], '=') - exp[i];
			vexp_name = malloc(len + 1);
			ft_memcpy(vexp_name, exp[i], len);
			vexp_name[len] = '\0';
			vexp_value = ft_strdup(ft_strchr(exp[i], '=') + 1);
			new_exp = new__exp(vexp_name, vexp_value);
			add_exp(&data->exp, new_exp);
		}
		free(vexp_name);
		free(vexp_value);
		i++;
	}
}