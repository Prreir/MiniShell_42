/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:05:53 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/13 10:38:58 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	exit_status;

void	delexp(t_exp *tmp)
{
	if (!tmp)
		return ;
	free(tmp->vexp_name);
	free(tmp->vexp_value);
	free(tmp);
}

void	clean_exp(t_exp *exp)
{
	t_exp	*tmp;

	while (exp)
	{
		tmp = exp;
		exp = exp->next;
		delexp(tmp);
	}
}

void	delenv(t_env *tmp)
{
	if (!tmp)
		return ;
	free(tmp->v_name);
	free(tmp->v_value);
	free(tmp);
}

void	clean_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env;
		env = env->next;
		delenv(tmp);
	}
}

void	clean_all(t_data *data)
{
	if (data->token)
		clean_token(&(data->token), free);
	if (data->env)
		clean_env(data->env);
	if (data->exp)
		clean_exp(data->exp);
	rl_clear_history();
}