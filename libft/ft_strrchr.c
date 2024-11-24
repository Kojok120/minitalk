/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:10:01 by kokamoto          #+#    #+#             */
/*   Updated: 2024/04/26 23:26:43 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*tmp;

	tmp = NULL;
	if ((char)c == '\0')
	{
		while (*str)
			str++;
		return ((char *)str);
	}
	while (*str)
	{
		if (*str == (char)c)
			tmp = (char *)str;
		str++;
	}
	return (tmp);
}

// int main(void)
// {
// 	printf("%p\n", ft_strrchr("teste", '\0'));
// 	printf("%p\n", strrchr("teste", '\0'));
// 	printf("%p\n", ft_strrchr("", '\0'));
// 	printf("%p\n", strrchr("", '\0'));

// 	return (0);
// }
