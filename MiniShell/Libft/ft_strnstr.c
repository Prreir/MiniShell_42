/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:23:21 by lugoncal          #+#    #+#             */
/*   Updated: 2022/11/03 14:23:22 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*src || (len == 0 && !*src))
		return ((char *)str);
	if (len == 0)
		return (0);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] == src[j] && str[i + j] && src[j] && (j + i) < len)
		{
			if (src[j + 1] == '\0')
				return ((char *)&(str[i]));
			j++;
		}
		i++;
	}
	return (0);
}
