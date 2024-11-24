/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:20:21 by kokamoto          #+#    #+#             */
/*   Updated: 2024/07/14 09:16:21 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putpointer_fd(void *p, int fd)
{
	char				*base;
	unsigned long long	ptr_value;
	int					len;
	int					i;
	char				*str;

	base = "0123456789abcdef";
	ptr_value = (unsigned long long)p;
	len = ft_hexlen(ptr_value);
	str = (char *)malloc(sizeof(char) * (len + 3));
	if (!str)
		return (0);
	i = len + 1;
	str[0] = '0';
	str[1] = 'x';
	str[len + 2] = '\0';
	while (i > 1)
	{
		str[i] = base[ptr_value % 16];
		ptr_value /= 16;
		i--;
	}
	ft_putstr_fd(str, fd);
	free(str);
	return (len + 2);
}
