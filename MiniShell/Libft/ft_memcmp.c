/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:19:49 by lugoncal          #+#    #+#             */
/*   Updated: 2022/11/07 11:19:50 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	a;
	size_t	i;

	a = 0;
	i = 0;
	while (a < n)
	{
		if (*(unsigned char *)(str1 + a) != *(unsigned char *)(str2 + a))
		{
			i = (*(unsigned char *)(str1 + a) - *(unsigned char *)(str2 + a));
			return (i);
		}
		a++;
	}
	return (0);
}
