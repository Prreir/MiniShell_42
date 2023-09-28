/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:38:56 by lugoncal          #+#    #+#             */
/*   Updated: 2023/09/28 09:52:59 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	valid(t_data *data)
{
	if (!ft_strlen(data->input))
	{
		free(data->input);
		return (1);
	}
	add_history(data->input);
	return (0);
}

void	boom(t_data *data)
{
	free(data->input);
}

void	error_msg(t_data *data, char *msg, int status)
{
	if (data)
		boom(data);
	printf("%s\n", msg);
	exit(status);
}
