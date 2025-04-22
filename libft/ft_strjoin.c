/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:01:45 by sel-hime          #+#    #+#             */
/*   Updated: 2024/10/29 18:18:02 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	slen1;
	size_t	slen2;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	p = malloc((slen1 + slen2 + 1) * sizeof(char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1, slen1 + 1);
	ft_strlcat(p, s2, slen2 + slen1 + 1);
	return (p);
}
