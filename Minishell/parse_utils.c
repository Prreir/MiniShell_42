/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:29:59 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/13 10:26:58 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	exit_status;

void	file_heap(char *file, char *delimiter)
{
	if (!file)
		exit(EXIT_FAILURE);
	if (ft_strlen(file) > 9999)
	{
		print_error("error:EOF too long", 1);
		free(file);
		exit(EXIT_FAILURE);
	}
	ft_memset(delimiter, 0, 10000);
	ft_memmove(delimiter, file, ft_strlen(file));
	free(file);
}

void	restore_save(int *save)
{
	dup2(save[IN], STDIN_FILENO);
	close(save[IN]);
	dup2(save[OUT], STDOUT_FILENO);
	close(save[OUT]);
}

void	start_save(int	*save)
{
	save[IN] = dup(STDIN_FILENO);
	save[OUT] = dup(STDOUT_FILENO);
}