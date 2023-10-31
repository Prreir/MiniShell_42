/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:51:55 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/25 14:09:51 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	l;

	if (!dest && !src)
		return (0);
	l = 0;
	while (l < n)
	{
		((unsigned char *)dest)[l] = ((unsigned char *)src)[l];
		l++;
	}
	return (dest);
}
