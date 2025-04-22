/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <sel-hime@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:46:09 by sel-hime          #+#    #+#             */
/*   Updated: 2025/04/18 22:01:51 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_name(char *name)
{
	char	*ext;
	int		i;
	int		j;
	int		fd;

	ext = ".ber";
	j = 4;
	i = ft_strlen(name);
	while (name[i] == ext[j])
	{
		i--;
		j--;
	}
	if (!(j == -1 && i >= 0 && name[i] != '/'))
		do_error(NULL, "Enter a valid file path\n", 0);
	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		perror(name);
		exit(1);
	}
}
