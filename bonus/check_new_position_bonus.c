/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_new_position_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <sel-hime@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:46:11 by sel-hime          #+#    #+#             */
/*   Updated: 2025/04/20 18:02:16 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	render2(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
	{
		if (game->data.direction == 3)
			mlx_put_image_to_window(game->mlx, game->win, game->player_img_down,
				j * 32, i * 32);
		else if (game->data.direction == 4)
			mlx_put_image_to_window(game->mlx, game->win, game->player_img_left,
				j * 32, i * 32);
		else if (game->data.direction == 2)
			mlx_put_image_to_window(game->mlx, game->win,
				game->player_img_right, j * 32, i * 32);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->player_img_up, j
				* 32, i * 32);
	}
	else if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img, j * 32, i
			* 32);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor_img, j * 32, i
			* 32);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collect_img, j * 32,
			i * 32);
}

static void	handle_exit(t_game *game)
{
	if (game->exit_x == game->data.x && game->exit_y == game->data.y)
		game->map[game->exit_y][game->exit_x] = 'P';
	else if (game->collect)
		game->map[game->exit_y][game->exit_x] = '0';
	else
	{
		game->map[game->exit_y][game->exit_x] = 'E';
		mlx_put_image_to_window(game->mlx, game->win, game->exit_on_img,
			game->exit_x * 32, game->exit_y * 32);
	}
}

void	render_map(t_game *game)
{
	int		i;
	int		j;
	char	*moves;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			handle_exit(game);
			render2(game, i, j);
			if (game->map[i][j] == 'T')
				mlx_put_image_to_window(game->mlx, game->win,
					game->enemy_img, j * 32, i * 32);
			moves = ft_itoa(game->moves);
			if (!moves)
			{
				ft_putstr_fd("Error\nAllocation Failed\n", 2);
				free_img(game);
			}
			mlx_string_put(game->mlx, game->win, 10, 15, 65280, moves);
			free(moves);
		}
	}
}

static void	check_new_position_exit(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		game->moves++;
		msg(1);
		free_img(game);
	}
	else if (game->map[y][x] == 'T')
	{
		game->moves++;
		msg(0);
		free_img(game);
	}
}

void	check_new_position(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0')
	{
		game->map[game->data.y][game->data.x] = '0';
		game->map[y][x] = 'P';
		game->data.x = x;
		game->data.y = y;
		game->moves++;
	}
	else if (game->map[y][x] == 'C')
	{
		game->map[game->data.y][game->data.x] = '0';
		game->map[y][x] = 'P';
		game->data.x = x;
		game->data.y = y;
		game->collect--;
		game->moves++;
	}
	else
		check_new_position_exit(game, x, y);
	render_map(game);
}
