/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:20:18 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/25 13:33:38 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str, const void *src, size_t n)
{
	size_t	l;

	if (!str && !src)
		return (0);
	l = 0;
	if ((size_t)str - (size_t)src < n)
	{
		l = n - 1;
		while (l < n)
		{
			((unsigned char *)str)[l] = ((unsigned char *)src)[l];
			l--;
		}
	}
	else
	{
		while (l < n)
		{
			((unsigned char *)str)[l] = ((unsigned char *)src)[l];
			l++;
		}
	}
	return (str);
}
