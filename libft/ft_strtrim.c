/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:30:58 by sel-hime          #+#    #+#             */
/*   Updated: 2024/10/30 11:56:51 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	isthere(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	first(const char *s1, const char *set)
{
	int	count;

	count = 0;
	while (s1[count] && isthere(set, s1[count]))
		count++;
	return (count);
}

static int	last(const char *s1, const char *set)
{
	int	count;
	int	i;

	count = 0;
	i = (int)ft_strlen(s1) - 1;
	while (i >= 0 && isthere(set, s1[i]))
	{
		count++;
		i--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		fs;
	int		nlen;
	int		slen;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	slen = ft_strlen(s1);
	fs = first(s1, set);
	nlen = slen - fs - last(s1, set);
	if (nlen < 0)
		nlen = 0;
	ptr = malloc((nlen + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i] && i < nlen)
	{
		ptr[i] = s1[i + fs];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
