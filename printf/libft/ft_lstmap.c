/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:13:58 by juzoanya          #+#    #+#             */
/*   Updated: 2021/12/22 14:27:21 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (new == NULL)
		return (NULL);
	temp = new;
	while (lst != NULL)
	{
		lst = lst->next;
		new->next = ft_lstnew(f(lst->content));
		if (!(new->next))
		{
			ft_lstclear(&temp, del);
			return (NULL);
		}
		new = new->next;
	}
	return (temp);
}
