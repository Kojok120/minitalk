/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:18:15 by kokamoto          #+#    #+#             */
/*   Updated: 2024/04/27 14:58:25 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_max(size_t i, size_t j)
{
	if (i >= j)
		return (i);
	else
		return (j);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (i == ft_max(ft_strlen(s1), ft_strlen(s2)))
			return (0);
		i++;
	}
	return (0);
}

// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
// 	char s1[] = "kokamoto";
// 	char s2[] = "kokamoto";

// 	printf("ft:     %d\n", ft_strncmp(s1, s2, 12));
// 	printf("origin: %d\n", strncmp(NULL, NULL, 0));
// }