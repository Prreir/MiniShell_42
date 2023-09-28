/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_birth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:02:53 by lugoncal          #+#    #+#             */
/*   Updated: 2023/09/28 11:05:53 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_env *ft_new_env(char *venv_name, char *venv_value)
{
	t_env *new_env;

	new_env = malloc(sizeof(t_env));
	if (!new_env)
		return (0);
	new_env->venv_name = ft_strdup(venv_name);
	new_env->venv_value = ft_strdup(venv_value);
	new_env->next = NULL;
	return (new_env);
}

t_env	*ft_last_env(t_env *env)
{
	if (env)
	{
		while (env->next != NULL)
			env = env->next;
		return (env);
	}
	return (NULL);
}

void ft_env_to_the_back(t_env **env, t_env *new)
{
	t_env *tail;

	if (!new)
		return ;
	if (!*env)
	{
		*env = new;
		return ;
	}
	tail = ft_last_env(*env);
	tail->next = new;
}

void	env_birth(t_data *data, char **env)
{
	size_t len;
	int i;
	char *venv_name;
	char *venv_value;
	t_env *new_env;

	i = 0;
	while (env[i])
	{
		if (ft_strchr(env[i], '='))
		{
			len = ft_strchr(env[i], '=') - env[i];
			venv_name = malloc(len + 1);
			ft_memcpy(venv_name, env[i], len);
			venv_name[len] = '\0';
			venv_value = ft_strdup(ft_strchr(env[i], '=') + 1);
			new_env = ft_new_env(venv_name, venv_value);
			ft_env_to_the_back(&data->env, new_env);
		}
		free(venv_name);
		free(venv_value);
		i++;
	}
}