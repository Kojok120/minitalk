/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:26:35 by kokamoto          #+#    #+#             */
/*   Updated: 2024/05/08 23:01:51 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)&haystack[0]);
	if (len == 0 || len < ft_strlen(needle) || ft_strlen(haystack) == 0)
		return (NULL);
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (i + j < len && haystack[i + j] == needle[j] && needle[j])
				j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {
//     char haystack[30] = "aaabcabcd";
//     char needle[10] = "aabc";

// //     printf("ft    : %p\n", ft_strnstr(haystack, needle, 20));
// //     printf("origin    : %p\n", strnstr(haystack, needle, 20));
// //     printf("ft    : %p\n", ft_strnstr(0, "fake", 3));
// //     printf("origin: %p\n", strnstr(0, "fake", 3));
// //     printf("ft    : %p\n", ft_strnstr("fake", 0, 3));
// //     printf("origin: %p\n", strnstr("fake", 0, 3));
// //     printf("ft    : %p\n", ft_strnstr(haystack, needle, -1));
// //     printf("origin    : %p\n", strnstr(haystack, needle, -1));
//     	printf("origin    : %p\n", strnstr(NULL, "1", 0));
// 		printf("ft    : %p\n", ft_strnstr(NULL, "1", 0));
// }