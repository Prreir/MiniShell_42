/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:18:20 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/13 10:23:56 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	cmd_free(char **ptr)
{
    int i;

    i = 0;
    while (ptr[i])
        i++;
    while (i > 0)
    {
        free(ptr[i - 1]);
        i--;
    }
    free(ptr);
}

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

void	boom_input(t_data *data)
{
	free(data->input);
	data->input = NULL;
}

void	boom(t_data *data)
{
	if (data->env)
		boom_env(data->env);
	rl_clear_history();
}
