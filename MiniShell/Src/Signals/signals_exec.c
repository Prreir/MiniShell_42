/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:30:16 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/25 11:36:27 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	g_exit_status;

void	exec_ctrl_c(int signal)
{
	(void)signal;
	g_exit_status = EXIT_CTRL_C;
	write(1, "\n", 1);
}

void	exec_ctrl_bslash(int signal)
{
	(void)signal;
	g_exit_status = 131;
	printf("Quit (core dumped)\n");
}

void	signals_exec(void)
{
	signal(SIGINT, exec_ctrl_c);
	signal(SIGQUIT, exec_ctrl_bslash);
}