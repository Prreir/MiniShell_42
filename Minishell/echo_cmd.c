/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:59:20 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/13 11:06:06 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	print_word(char **word, int i, int flag)
{
	while (word[i])
	{
		printf("%s", word[i]);
		if (word[i + 1])
			printf(" ");
		i++;
	}
	if (flag)
		printf("\n");
}

void	echo_cmd(char **cmd)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	if (!cmd || !cmd[i])
	{
		printf("\n");
		return ;
	}
	while (cmd[i] && ft_strcmp(cmd[i], "-n") == 0)
	{
		flag = 0;
		i++;
	}
	print_word(cmd, i, flag);
}