/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:57:34 by lugoncal          #+#    #+#             */
/*   Updated: 2022/11/07 14:57:35 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*ptr;

	ptr = (void *)malloc(nitems * size);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, (nitems * size));
	return (ptr);
}
