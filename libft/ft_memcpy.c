/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:09:27 by sel-hime          #+#    #+#             */
/*   Updated: 2024/10/28 16:36:07 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t n)
{
	size_t	i;

	if (!to && !from)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)to)[i] = ((unsigned char *)from)[i];
		i++;
	}
	return (to);
}
