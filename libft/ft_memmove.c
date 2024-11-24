/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:06:46 by kokamoto          #+#    #+#             */
/*   Updated: 2024/04/22 20:11:50 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*p1;
	unsigned char		*p2;
	size_t				i;

	p1 = src;
	p2 = dest;
	if (p2 > p1)
	{
		i = n;
		while (i-- > 0)
			p2[i] = p1[i];
	}
	if (p1 > p2)
	{
		i = 0;
		while (i < n)
		{
			p2[i] = p1[i];
			i++;
		}
	}
	return (dest);
}
