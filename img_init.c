/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <sel-hime@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:45:36 by sel-hime          #+#    #+#             */
/*   Updated: 2025/04/19 21:09:17 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_img(t_game *game)
{
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->player_img_left)
		mlx_destroy_image(game->mlx, game->player_img_left);
	if (game->player_img_right)
		mlx_destroy_image(game->mlx, game->player_img_right);
	if (game->player_img_up)
		mlx_destroy_image(game->mlx, game->player_img_up);
	if (game->player_img_down)
		mlx_destroy_image(game->mlx, game->player_img_down);
	if (game->collect_img)
		mlx_destroy_image(game->mlx, game->collect_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->exit_on_img)
		mlx_destroy_image(game->mlx, game->exit_on_img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_all(game);
	exit(1);
}

static void	check_img_init(t_game *game)
{
	if (!game->floor_img || !game->player_img_left || !game->player_img_right
		|| !game->player_img_up || !game->player_img_down || !game->collect_img
		|| !game->wall_img || !game->exit_on_img)
	{
		ft_putstr_fd("Error\nCheck the textures files\n", 2);
		free_img(game);
	}
}

void	img_init(t_game *game)
{
	int	h;
	int	w;

	game->floor_img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &w,
			&h);
	game->player_img_left = mlx_xpm_file_to_image(game->mlx,
			"textures/player/left.xpm", &w, &h);
	game->player_img_right = mlx_xpm_file_to_image(game->mlx,
			"textures/player/right.xpm", &w, &h);
	game->player_img_up = mlx_xpm_file_to_image(game->mlx,
			"textures/player/up.xpm", &w, &h);
	game->player_img_down = mlx_xpm_file_to_image(game->mlx,
			"textures/player/down.xpm", &w, &h);
	game->collect_img = mlx_xpm_file_to_image(game->mlx, "textures/collect.xpm",
			&w, &h);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w,
			&h);
	game->exit_on_img = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&w, &h);
	check_img_init(game);
}
