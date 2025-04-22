/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:45 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/10 14:01:42 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str && !len)
		return (0);
	if (sub[0] == '\0' || sub == str)
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == sub[j] && (i + j) < len)
		{
			if (str[i + j] == '\0' && sub[j] == '\0')
				return ((char *)&str[i]);
			j++;
		}
		if (sub[j] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (0);
}
