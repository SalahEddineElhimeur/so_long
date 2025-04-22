/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:57:52 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/01 17:58:16 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	slen;

	if (!s)
		return ;
	slen = ft_strlen(s);
	i = 0;
	while (i < slen)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
