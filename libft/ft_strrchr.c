/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:12:31 by sel-hime          #+#    #+#             */
/*   Updated: 2024/10/28 14:16:03 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	int	i;
	int	p;

	i = 0;
	p = -1;
	while (str[i])
	{
		if (str[i] == (char)n)
			p = i;
		i++;
	}
	if (n == '\0')
		return ((char *)(str + i));
	if (p < 0)
		return (NULL);
	return ((char *)(str + p));
}
