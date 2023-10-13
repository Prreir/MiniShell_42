/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:56:02 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/13 16:07:03 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void    boom_env(t_env *env)
{
    t_env   *tmp;

    while (env)
    {
        tmp = env;
        env = env->next;
        if (!tmp)
            break;
        free(tmp->v_name);
        free(tmp->v_value);
        free(tmp);
    }
}

t_env	*new_env(char *v_name, char *v_value)
{
	t_env *new_envp;

	new_envp = malloc(sizeof(t_env));
	if (!new_envp)
		return (0);
	new_envp->v_name = ft_strdup(v_name);
	new_envp->v_value = ft_strdup(v_value);
	new_envp->next = NULL;
	return (new_envp);
}

t_env	*last_env(t_env *env)
{
	if (env)
	{
		while (env->next != NULL)
			env = env->next;
		return (env);
	}
	return (NULL);
}

void	env_to_the_back(t_env **env, t_env *new)
{
	t_env *tail;

	if (!new)
		return ;
	if (!*env)
	{
		*env = new;
		return ;
	}
	tail = last_env(*env);
	tail->next = new;
}

void	env_create(t_data *data, char **env)
{
	size_t len;
	int i;
	char *v_name;
	char *v_value;
	t_env *new_envp;

	i = 0;
	while (env[i])
	{
		if (ft_strchr(env[i], '='))
		{
			len = ft_strchr(env[i], '=') - env[i];
			v_name = malloc(len + 1);
			ft_memcpy(v_name, env[i], len);
			v_name[len] = '\0';
			v_value = ft_strdup(ft_strchr(env[i], '=') + 1);
			new_envp = new_env(v_name, v_value);
			env_to_the_back(&data->env, new_envp);
		}
		free(v_name);
		free(v_value);
		i++;
	}
}