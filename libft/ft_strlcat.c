/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:43:08 by kokamoto          #+#    #+#             */
/*   Updated: 2024/05/08 22:56:58 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	if (destsize == 0)
		return (ft_strlen(src));
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (destsize <= dest_len)
		return (destsize + src_len);
	if (dest == NULL)
		return (src_len + 1);
	while (src[i] && dest_len + i < destsize - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

// int main(void)
// {
// 	char src1[] = "rhori";
// 	printf("%zu\n", strlcat(NULL, src1, 0));
// 	printf("%zu\n", ft_strlcat(NULL, src1, 0));
// 	printf("%zu\n", strlcat(src1, NULL, 0));
// 	printf("%zu\n", ft_strlcat(src1, NULL, 0));
// }
