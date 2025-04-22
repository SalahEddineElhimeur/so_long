/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:00:09 by sel-hime          #+#    #+#             */
/*   Updated: 2024/10/30 12:48:54 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	isin(const char s, char c)
{
	return (s == c);
}

static int	countwords(const char *s, char c)
{
	int	count;
	int	in;

	in = 0;
	count = 0;
	while (*s)
	{
		if (isin(*s, c))
		{
			s++;
			in = 0;
		}
		else
		{
			if (!in)
			{
				in = 1;
				count++;
			}
			s++;
		}
	}
	return (count);
}

static char	*fill(char const **s, char c)
{
	int			lw;
	char const	*start;
	char		*ptr;

	lw = 0;
	while (**s && isin(**s, c))
		(*s)++;
	if (!**s)
		return (NULL);
	start = *s;
	while (**s && !isin(**s, c))
	{
		lw++;
		(*s)++;
	}
	ptr = malloc(lw + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, start, lw);
	ptr[lw] = '\0';
	return (ptr);
}

char	**ft_split(const char *s, char c)
{
	int		words;
	char	**p;
	int		w;

	if (!s)
		return (NULL);
	words = countwords(s, c);
	p = malloc((words + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	w = 0;
	while (w < words)
	{
		p[w] = fill(&s, c);
		if (!p[w])
		{
			while (w > 0)
				free(p[--w]);
			return (free(p), NULL);
		}
		w++;
	}
	p[w] = NULL;
	return (p);
}
