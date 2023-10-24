/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:57:14 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/24 09:41:10 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	g_exit_status;

int	set_env(char *key, char *newvalue, t_data *data)
{
	t_env	*newenv;
	t_env	*find;

	find = search_env(key, data);
	if (find)
	{
		free(find->v_value);
		find->v_value = ft_strdup(newvalue);
		return (0);
	}
	else
	{
		newenv = new_env(key, newvalue);
		env_to_the_back(&data->env, newenv);
		return (0);
	}
	return (-1);
}

void	print_env(t_data *data)
{
	t_env	*print;

	print = data->env;
	while (print)
	{
		printf("%s=%s\n", print->v_name, print->v_value);
		print = print->next;
	}
	g_exit_status = 0;
}

char	**array_env(t_data *data)
{
	int		num;
	int		i;
	t_env	*cur;
	char	**env;

	num = 0;
	cur = data->env;
	while (cur != NULL)
	{
		num++;
		cur = cur->next;
	}
	env = ft_calloc(sizeof(char **), num + 1);
	cur = data->env;
	i = 0;
	while (cur != NULL)
	{
		env[i] = join_three(cur->v_name, "=", cur->v_value);
		cur = cur->next;
		i++;
	}
	env[i] = NULL;
	return (env);
}

t_env	*search_env(char *name, t_data *data)
{
	t_env	*search;

	search = data->env;
	while (search != NULL)
	{
		if (ft_strcmp(name, search->v_name) == 0)
			return (search);
		search = search->next;
	}
	return (NULL);
}

char	*get_env(char *name, t_data *data)
{
	t_env	*search;

	search = data->env;
	while (search != NULL)
	{
		if (ft_strcmp(name, search->v_name) == 0)
			return (search->v_value);
		search = search->next;
	}
	return (NULL);
}
