/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_helper_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <sel-hime@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:46:05 by sel-hime          #+#    #+#             */
/*   Updated: 2025/04/20 17:27:43 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if ((i == 0 || i == game->height - 1) || (j == 0 || j == game->width
					- 1))
			{
				if (game->map[i][j] != '1')
				{
					get_next_line(-1);
					do_error(game, "The surrending should be walls\n", 1);
				}
			}
			j++;
		}
		i++;
	}
}

static void	float_fill(char **copy, int y, int x)
{
	if (copy[y][x] == '1' || copy[y][x] == 'V' || copy[y][x] == 'T')
		return ;
	copy[y][x] = 'V';
	float_fill(copy, y - 1, x);
	float_fill(copy, y + 1, x);
	float_fill(copy, y, x - 1);
	float_fill(copy, y, x + 1);
}

static void	allocate_map(t_game *game)
{
	game->map = (char **)ft_calloc((game->height + 1), sizeof(char *));
	if (!game->map)
		do_error(game, "Allocation Failed\n", 0);
	game->copy = (char **)ft_calloc((game->height + 1), sizeof(char *));
	if (!game->copy)
	{
		free(game->map);
		do_error(game, "Allocation Failed\n", 0);
	}
}

void	helper2(t_game *game, int fd, char *name)
{
	int	i;

	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		perror(name);
		free(game);
		exit(1);
	}
	allocate_map(game);
	i = -1;
	while (++i < game->height)
	{
		game->map[i] = get_next_line(fd);
		game->copy[i] = ft_strdup(game->map[i]);
		if (!game->copy[i])
		{
			get_next_line(-1);
			do_error(game, "Allocation Failed\n", 1);
		}
	}
	get_next_line(-1);
}

void	helper3(t_game *game)
{
	int	i;
	int	j;

	float_fill(game->copy, game->data.y, game->data.x);
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->copy[i][j] == 'P' || game->copy[i][j] == 'E'
				|| game->copy[i][j] == 'C')
			{
				do_error(game, "Invalid Path in Map\n", 1);
			}
			j++;
		}
		i++;
	}
}
