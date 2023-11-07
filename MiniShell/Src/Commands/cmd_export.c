/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:50:16 by lugoncal          #+#    #+#             */
/*   Updated: 2023/11/07 13:19:20 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	g_exit_status;

void	only_export(t_data *data, char *key)
{
	if (get_exp(key, data) == NULL)
		set_exp(key, NULL, data);
}

int	is_valid_key(char *key, char *cmd, char *type)
{
	int	i;

	i = 0;
	if (!(ft_isalpha(cmd[i]) || cmd[i] == '_'))
	{
		printf("%s: `%s': not a valid identifier\n", type, cmd);
		return (0);
	}
	i++;
	while (key[i] != '\0')
	{
		if (!(ft_isalnum(key[i]) || key[i] == '_'))
		{
			printf("%s: `%s': not a valid identifier\n", type, key);
			return (0);
		}
		i++;
	}
	return (1);
}

void	export_single(char *cmd, t_data *data)
{
	char	*key;
	char	*value;
	int		len;

	len = 0;
	while (cmd[len] != '\0' && cmd[len] != '=')
		len++;
	key = ft_substr(cmd, 0, len);
	if (!is_valid_key(key, cmd, "export"))
	{
		free(key);
		return ;
	}
	if (cmd[len] != '=')
	{
		only_export(data, key);
		free(key);
		return ;
	}
	value = ft_strdup(cmd + len + 1);
	set_env(key, value, data);
	set_exp(key, value, data);
	free(key);
	free(value);
}

void	export_cmd(t_data *data, char **cmd)
{
	int	i;

	i = -1;
	if (has_pipe(data))
		return ;
	while (cmd[++i])
		export_single(cmd[i], data);
	g_exit_status = 0;
}
