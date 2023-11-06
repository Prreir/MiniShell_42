/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:16:18 by lugoncal          #+#    #+#             */
/*   Updated: 2023/11/06 11:06:57 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	file_heap(char *file, char *delimiter)
{
	if (!file)
		exit(EXIT_FAILURE);
	if (ft_strlen(file) > 9999)
	{
		print_error("error:EOF too long", 1, 0);
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

void	pipe_create(t_token *cur, int *old_in)
{
	int	new_pipe[2];

	dup2(*old_in, STDIN_FILENO);
	if (!cur)
		return ;
	pipe(new_pipe);
	dup2(new_pipe[OUT], STDOUT_FILENO);
	close(new_pipe[OUT]);
	*old_in = new_pipe[IN];
}

void	start_save(int	*save)
{
	save[IN] = dup(STDIN_FILENO);
	save[OUT] = dup(STDOUT_FILENO);
}
