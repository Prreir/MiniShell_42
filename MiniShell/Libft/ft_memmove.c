/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:20:18 by lugoncal          #+#    #+#             */
/*   Updated: 2022/11/03 11:20:21 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str, const void *src, size_t n)
{
	if (!str && !src)
		return (0);
	if (src < str)
	{
		while (n != 0)
		{
			n--;
			((char *)str)[n] = ((char *)src)[n];
		}
	}
	else if (src > str)
		ft_memcpy(str, src, n);
	return (str);
}
