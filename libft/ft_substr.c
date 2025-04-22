/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:59:38 by sel-hime          #+#    #+#             */
/*   Updated: 2024/10/29 17:59:58 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	slen;

	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_calloc(1, sizeof(char)));
	if (len > slen - start)
		len = slen - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[i + start])
	{
		str[i] = ((char *)s)[i + start];
		i++;
	}
	str[len] = '\0';
	return (str);
}
