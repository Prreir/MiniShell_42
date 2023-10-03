/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:10:03 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/03 13:11:10 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	exit_status;

void print_env(t_data *data)
{
	t_env *print;

	print = data->env;
	while (lst)
	{
		printf("%s=%s\n", print->v_name, print->v_value );
		print = print->next;
	}
	exit_status = 0;
}

t_env *search_env(char *name, t_data *data)
{
	t_env *search;

	search = data->env;
	while (search != NULL)
	{
		if (ft_strcmp(name, search->v_name) == 0)
			return (search);
		search = search->next;
	}
	return (NULL);
}

int set_env(char *name, char *new_value, t_data *data)
{
	t_env *new_envp;
	t_env *search;

	search = search_env(name, data);
	if (search)
	{
		if (search->v_value != NULL)
			free(search->v_value);
		search->v_value = ft_strdup(new_value);
		return (0);
	}
	else
	{
		new_envp = new_env(name, new_value);
		env_to_the_back(&data->env, new_envp);
		return (0);
	}
	return (-1);
}

char *get_env(char *name, t_data *data)
{
	t_env *search;

	search = data->env;
	while (search != NULL)
	{
		if (ft_strcmp(name, search->v_name) == 0)
			return (search->v_value);
		search = search->next;
	}
	return (NULL);
}
