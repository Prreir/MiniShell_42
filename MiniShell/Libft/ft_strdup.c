/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:47:40 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/25 13:40:04 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*s2;

	if (!str)
		return (NULL);
	s2 = (char *)malloc(ft_strlen(str) + 1);
	if (!s2)
		return (0);
	ft_memcpy(s2, str, ft_strlen(str) + 1);
	return (s2);
}
