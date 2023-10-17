/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:57:14 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/17 12:00:02 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	exit_status;

void	print_env(t_data *data)
{
	t_env *print;

	print = data->env;
	while (print)
	{
		printf("%s=%s\n", print->v_name, print->v_value );
		print = print->next;
	}
	exit_status = 0;
}

char	**array_env(t_data *data)
{
	int	num;
	int	i;
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

char	*get_env(char *name, t_data *data)
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