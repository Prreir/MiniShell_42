/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:40:56 by lugoncal          #+#    #+#             */
/*   Updated: 2022/11/03 11:41:01 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	x;
	size_t	l;

	x = ft_strlen(src);
	l = 0;
	if (!dest || !src)
		return (0);
	if (size != 0)
	{
		while ((src[l] != '\0') && (l < size -1))
		{
			dest[l] = src[l];
			l++;
		}
		dest[l] = '\0';
	}
	return (x);
}
