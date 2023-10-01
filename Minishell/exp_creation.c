/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 10:22:26 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/01 10:23:45 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"


t_exp *ft_new_exp(char *vexp_name, char *vexp_value)
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

t_exp	*ft_last_exp(t_exp *exp)
{
	if (exp)
	{
		while (exp->next != NULL)
			exp = exp->next;
		return (exp);
	}
	return (NULL);
}

void ft_exp_to_the_back(t_exp **exp, t_exp *new)
{
	t_exp *tail;

	if (!new)
		return ;
	if (!*exp)
	{
		*exp = new;
		return ;
	}
	tail = ft_last_exp(*exp);
	tail->next = new;
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
			new_exp = ft_new_exp(vexp_name, vexp_value);
			ft_exp_to_the_back(&data->exp, new_exp);
		}
		free(vexp_name);
		free(vexp_value);
		i++;
	}
}