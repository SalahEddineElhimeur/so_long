/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <sel-hime@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:45:29 by sel-hime          #+#    #+#             */
/*   Updated: 2025/04/19 22:09:04 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	do_error(t_game *game, char *msg, int mode)
{
	write(2, "Error\n", 7);
	ft_putstr_fd(msg, 2);
	if (mode)
	{
		double_free(game->map);
		double_free(game->copy);
	}
	if (game)
		free(game);
	exit(1);
}

static void	read_metadeta(t_game *game)
{
	if (game->collect < 1)
		do_error(game, "You should enter at least one collectable\n", 1);
	if (!game->player)
		do_error(game, "You should add a player\n", 1);
	else if (game->player > 1)
		do_error(game, "You can't have more than one player\n", 1);
	if (!game->exit)
		do_error(game, "You should add an exit\n", 1);
	else if (game->exit > 1)
		do_error(game, "You can't have more than one exit\n", 1);
}

static void	read_map_helper(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'E')
	{
		game->exit_x = j;
		game->exit_y = i;
		game->exit++;
	}
	else if (game->map[i][j] != '0' && game->map[i][j] != '1')
		do_error(game, "You added a wrong character\n", 1);
}

void	read_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				game->data.y = i;
				game->data.x = j;
				game->player++;
			}
			else if (game->map[i][j] == 'C')
				game->collect++;
			else
				read_map_helper(game, i, j);
			j++;
		}
		i++;
	}
	read_metadeta(game);
}
