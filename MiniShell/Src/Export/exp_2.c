/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:13:16 by lugoncal          #+#    #+#             */
/*   Updated: 2023/11/03 14:53:05 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	g_exit_status;

t_exp	*search_exp(char *name, t_data *data)
{
	t_exp	*search;

	search = data->exp;
	while (search != NULL)
	{
		if (ft_strcmp(name, search->vexp_name) == 0)
			return (search);
		search = search->next;
	}
	return (NULL);
}

int	set_exp(char *name, char *new_value, t_data *data)
{
	t_exp	*new_exp;
	t_exp	*search;

	search = search_exp(name, data);
	if (search)
	{
		if (search->vexp_value != NULL)
			free(search->vexp_value);
		search->vexp_value = ft_strdup(new_value);
		return (0);
	}
	else
	{
		new_exp = new__exp(name, new_value);
		add_exp(&data->exp, new_exp);
		return (0);
	}
	return (-1);
}

char	*get_exp(char *name, t_data *data)
{
	t_exp	*search;

	search = data->exp;
	while (search != NULL)
	{
		if (ft_strcmp(name, search->vexp_name) == 0)
			return (search->vexp_value);
		search = search->next;
	}
	return (NULL);
}

void	print_exp(t_data *data)
{
	t_exp	*print;

	print = data->exp;
	while (print)
	{
		if (print->vexp_value == NULL)
			printf("declare -x %s\n", print->vexp_name);
		else
			printf("declare -x %s=\"%s\"\n", print->vexp_name, \
					print->vexp_value);
		print = print->next;
	}
	g_exit_status = 0;
}
