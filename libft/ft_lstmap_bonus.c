/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 08:53:13 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/01 08:53:15 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_elem;
	t_list	*new_list;

	new_list = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		new_elem = malloc(sizeof(t_list));
		if (!new_elem)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_elem->content = f(lst->content);
		new_elem->next = NULL;
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}
