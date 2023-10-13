/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 09:57:59 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/13 10:02:49 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	exit_status;

void	handle_exec_ctrl_c(int signal)
{
	(void)signal;
	exit_status = EXIT_CTRL_C;
	write(1, "\n", 1);
}

void	handle_exec_ctrl_bslash(int signal)
{
	(void)signal;
	exit_status = 131;
	printf("Quit (core dumped)\n");
}


void	register_signal(void)
{
	signal(SIGINT, handle_exec_ctrl_c);
	signal(SIGQUIT, handle_exec_ctrl_bslash);
}