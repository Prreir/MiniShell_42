/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:55:54 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/25 10:51:21 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	g_exit_status;

void	unset_envvariables(t_data *data, char *key)
{
	t_env	*temp;
	t_env	*prev;

	temp = data->env;
	prev = NULL;
	if (temp != NULL && temp->v_name == key)
	{
		data->env = temp->next;
		boom_env2(temp);
		return ;
	}
	while (temp != NULL && ft_strcmp(temp->v_name, key) != 0)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	prev->next = temp->next;
	boom_env2(temp);
}

void	unset_expvariables(t_data *data, char *key)
{
	t_exp	*temp;
	t_exp	*prev;

	temp = data->exp;
	prev = NULL;
	if (temp != NULL && temp->vexp_name == key)
	{
		data->exp = temp->next;
		boom_exp2(temp);
		return ;
	}
	while (temp != NULL && ft_strcmp(temp->vexp_name, key) != 0)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	prev->next = temp->next;
	boom_exp2(temp);
}

int	is_valid_key_unset(char *key, char *type)
{
	int	i;

	i = 0;
	if (!(ft_isalpha(key[i]) || key[i] == '_'))
	{
		printf("minishell: %s: `%s': not a valid identifier\n", type, key);
		return (0);
	}
	i++;
	while (key[i] != '\0')
	{
		if (!(ft_isalnum(key[i]) || key[i] == '_') || key[i] == '=' )
		{
			printf("minishell: %s: `%s': not a valid identifier\n", type, key);
			return (0);
		}
		i++;
	}
	return (1);
}

void	unset_cmd(t_data *data, char **cmd)
{
	char	*key;
	int		len;
	int		i;

	if (has_pipe(data))
		return ;
	i = -1;
	while (cmd[++i])
	{
		if (!is_valid_key_unset(cmd[i], "unset"))
			continue ;
		len = 0;
		while (cmd[i][len] != '\0')
			len++;
		key = ft_substr(cmd[i], 0, len);
		unset_expvariables(data, key);
		unset_envvariables(data, key);
		free(key);
	}
	g_exit_status = 0;
}
