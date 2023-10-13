/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:31:05 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/13 10:38:19 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	exit_status;

void	wait_and_update_main_signals(int pid, int *status)
{
	signal(SIGINT, SIG_IGN);
	waitpid(pid, status, 0);
	signal(SIGINT, ctrl_c);
}

void	handle_heredoc_ctrl_c(int signal)
{
	(void)signal;
	exit_status = 130;
	write (1, "\n", 1);
	exit(130);
}