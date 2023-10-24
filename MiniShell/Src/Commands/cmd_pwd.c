/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:45:14 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/24 10:32:24 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	g_exit_status;

void	pwd_cmd(void)
{
	char	pwd[256];

	getcwd(pwd, sizeof(pwd));
	printf("%s\n", pwd);
	g_exit_status = 0;
}
