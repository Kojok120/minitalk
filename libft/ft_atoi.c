/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:56:59 by kokamoto          #+#    #+#             */
/*   Updated: 2024/04/24 21:24:13 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign * num > LONG_MAX / 10
			|| (sign * num * 10 > LONG_MAX - (str[i] - '0')))
			return ((int)LONG_MAX);
		if (sign * num < LONG_MIN / 10
			|| (sign * num * 10 < LONG_MIN + (str[i] - '0')))
			return ((int)LONG_MIN);
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (sign * num);
}
