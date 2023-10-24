/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_signals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:27:29 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/17 14:32:01 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	g_exit_status;

void	wait_and_update_main_signals(int pid, int *status)
{
	signal(SIGINT, SIG_IGN);
	waitpid(pid, status, 0);
	signal(SIGINT, ctrl_c);
}

void	handle_heredoc_ctrl_c(int signal)
{
	(void)signal;
	g_exit_status = 130;
	write (1, "\n", 1);
	exit(130);
}
