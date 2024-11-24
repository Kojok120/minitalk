/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:40:04 by kokamoto          #+#    #+#             */
/*   Updated: 2024/04/24 18:41:01 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *cnt)
{
	t_list	*ndptr;

	ndptr = malloc(sizeof(t_list));
	if (ndptr == NULL)
		return (NULL);
	ndptr->content = cnt;
	ndptr->next = NULL;
	return (ndptr);
}
