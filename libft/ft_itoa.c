/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:05:17 by kokamoto          #+#    #+#             */
/*   Updated: 2024/04/27 14:56:49 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int		len;
	long	n2;

	len = 0;
	n2 = n;
	if (n2 == 0)
		return (1);
	if (n2 < 0)
	{
		n2 *= -1;
		len++;
	}
	while (n2 > 0)
	{
		n2 = n2 / 10;
		len++;
	}
	return (len);
}

static char	ft_zero_minus(int n)
{
	if (n == 0)
		return ('0');
	else
		return ('-');
}

char	*ft_itoa(int n)
{
	int		i;
	long	n2;
	int		len;
	char	*array;

	i = 0;
	n2 = n;
	len = ft_intlen(n2);
	array = (char *)malloc(len + 1);
	if (array == NULL)
		return (NULL);
	if (n2 == 0 || n2 < 0)
	{
		array[0] = ft_zero_minus(n2);
		n2 *= -1;
	}
	while (n2 > 0)
	{
		array[len - 1 - i] = n2 % 10 + '0';
		n2 = n2 / 10;
		i++;
	}
	array[len] = '\0';
	return (array);
}
