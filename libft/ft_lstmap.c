/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:23:41 by kokamoto          #+#    #+#             */
/*   Updated: 2024/04/28 11:04:36 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*current;
	void	*tmp;

	if (lst == NULL)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		current = ft_lstnew(tmp);
		if (current == NULL)
		{
			del(tmp);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, current);
		lst = lst->next;
	}
	return (newlst);
}
