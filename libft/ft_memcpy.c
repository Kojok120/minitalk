/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:20:22 by kokamoto          #+#    #+#             */
/*   Updated: 2024/04/27 14:57:31 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*p1;
	unsigned char		*p2;
	size_t				i;

	p1 = src;
	p2 = dest;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		p2[i] = p1[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	printf("%p\n", ft_memcpy(NULL, NULL, 3));
// 	printf("%p\n", memcpy(NULL, NULL, 3));
// }