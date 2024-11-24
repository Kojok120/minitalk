/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:38:03 by kokamoto          #+#    #+#             */
/*   Updated: 2024/04/27 17:38:43 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(char const *s, char c)
{
	int	i;
	int	count;
	int	n;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			n = 0;
			count++;
			while (s[i + n] && s[i + n] != c)
				n++;
			i += n - 1;
		}
		i++;
	}
	return (count);
}

static char	*ft_strndup(char const *src, int n)
{
	int		i;
	char	*array;

	array = (char *)malloc((n + 1) * sizeof(char));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		array[i] = src[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

static char	**ft_split2(char const *s, char c, char **array, int i)
{
	int	j;
	int	n;

	j = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			n = 0;
			while (s[i + n] && s[i + n] != c)
				n++;
			array[j] = ft_strndup(&s[i], n);
			if (array[j] == NULL)
			{
				while (j > 0)
					free(array[--j]);
				free(array);
				return (NULL);
			}
			i += n - 1;
			j++;
		}
	}
	array[j] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (s == NULL)
		return (NULL);
	array = (char **)malloc((countwords(s, c) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	return (ft_split2(s, c, array, -1));
}

// int main (void)
// {
// 	printf("%d", countwords("hello!", ' '));
// 	printf("%d", countwords_ori("hello!", ' '));
// 	return (0);
// }