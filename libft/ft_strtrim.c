/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:38:44 by kokamoto          #+#    #+#             */
/*   Updated: 2024/05/08 19:57:40 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ans;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	while (isset(s1[start], set) == 1)
		start++;
	end = ft_strlen(s1);
	if (end > 0)
	{
		while (isset(s1[end - 1], set) == 1 && end > start)
		end--;
	}
	if (*set == '\0')
		ans = (char *)malloc(ft_strlen(s1) + 1);
	else
		ans = (char *)malloc(end - start + 1);
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (start < end)
		ans[i++] = s1[start++];
	ans[i] = '\0';
	return (ans);
}

// #include <string.h>

// int main(void)
// {
// 	printf("%s\n", ft_strtrim("hello, world hello world hello", "hello"));
// 	printf("%p\n", ft_strtrim("  \t \t \n   \n\n\n\t", " \n\t"));
// 	//printf("%d\n", strcmp("", ft_strtrim("  \t \t \n   \n\n\n\t", " \n\t")));
// }