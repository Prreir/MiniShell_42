/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:15:43 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/10 11:16:18 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int exit_status;

char	*append_char(char *str, char c)
{
	char *tmp;

	if (!str || !c)
		return (NULL);
	tmp = malloc(ft_strlen(str) + 2);
	ft_memcpy(tmp, str, ft_strlen(str));
	tmp[ft_strlen(str)] = c;
	tmp[ft_strlen(str) + 1] = '\0';
	free(str);
	return (tmp);
}