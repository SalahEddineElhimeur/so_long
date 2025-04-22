/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:34:49 by sel-hime          #+#    #+#             */
/*   Updated: 2024/10/31 11:35:32 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		nbr;
	t_list	*temp;

	nbr = 0;
	temp = lst;
	while (temp)
	{
		nbr++;
		temp = temp->next;
	}
	return (nbr);
}
