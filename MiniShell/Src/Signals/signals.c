/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:16:04 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/17 14:29:00 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	g_exit_status;

int	ctrl_d(char *input)
{
	if (!input)
	{
		printf ("exit\n");
		return (1);
	}
	return (0);
}

void	ctrl_c(int sig)
{
	(void)sig;
	g_exit_status = EXIT_CTRL_C;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	signals_ctrl(void)
{
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}
