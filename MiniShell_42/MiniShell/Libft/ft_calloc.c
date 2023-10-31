/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:57:34 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/25 13:17:13 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	tot_size;
	void	*dest;

	tot_size = size * nitems;
	dest = malloc(tot_size);
	if (!dest)
		return (0);
	ft_memset(dest, 0, tot_size);
	return (dest);
}
