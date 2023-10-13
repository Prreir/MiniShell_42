/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:03:25 by lugoncal          #+#    #+#             */
/*   Updated: 2022/11/09 10:03:27 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*dest;

	j = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		dest = malloc(sizeof(char) * 1);
		if (!dest)
			return (0);
		dest[0] = '\0';
		return (dest);
	}
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	while (len > j && s[j] != '\0')
	{
		dest[j] = s[start];
		j++;
		start++;
	}
	dest[j] = '\0';
	return (dest);
}
