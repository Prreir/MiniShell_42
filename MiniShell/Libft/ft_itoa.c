/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:51:48 by lugoncal          #+#    #+#             */
/*   Updated: 2022/11/09 13:51:50 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_cont(int n)
{
	size_t	cont;

	cont = 0;
	if (n <= 0)
		cont++;
	while (n != 0)
	{
		n = n / 10;
		cont++;
	}
	return (cont);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		i;
	size_t	cont;

	i = 1;
	cont = ft_cont(n);
	dest = malloc(sizeof(char) * (cont + 1));
	if (!dest)
		return (0);
	dest[cont] = '\0';
	cont--;
	if (n < 0)
	{
		dest[0] = '-';
		i = -1;
	}
	else if (n == 0)
		dest[cont] = '0';
	while (n != 0)
	{
		dest[cont] = (((n % 10) * i) + 48);
		n = n / 10;
		cont--;
	}
	return (dest);
}
