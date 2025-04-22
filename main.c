/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <sel-hime@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:45:32 by sel-hime          #+#    #+#             */
/*   Updated: 2025/04/20 17:40:32 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_game	*init(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		exit(1);
	}
	game->player = 0;
	game->collect = 0;
	game->exit = 0;
	game->moves = 0;
	game->floor_img = NULL;
	game->player_img_left = NULL;
	game->player_img_right = NULL;
	game->player_img_up = NULL;
	game->player_img_down = NULL;
	game->collect_img = NULL;
	game->wall_img = NULL;
	game->exit_on_img = NULL;
	game->exit_x = -1;
	game->exit_y = -1;
	game->data.direction = 1;
	return (game);
}

static int	handle_moves(int key, t_game *game)
{
	if (key == 65307)
		free_img(game);
	if (key == 119 || key == 65362)
	{
		game->data.direction = 1;
		check_new_position(game, game->data.x, game->data.y - 1);
	}
	else if (key == 115 || key == 65364)
	{
		game->data.direction = 3;
		check_new_position(game, game->data.x, game->data.y + 1);
	}
	else if (key == 100 || key == 65363)
	{
		game->data.direction = 2;
		check_new_position(game, game->data.x + 1, game->data.y);
	}
	else if (key == 97 || key == 65361)
	{
		game->data.direction = 4;
		check_new_position(game, game->data.x - 1, game->data.y);
	}
	return (0);
}

static void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		do_error(game, "mlx_init Failed\n", 1);
	}
	game->win = mlx_new_window(game->mlx, game->width * 32, game->height * 32,
			"so_long");
	if (!game->win)
	{
		perror("Error: mlx_new_window failed");
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_all(game);
		exit(1);
	}
	img_init(game);
	render_map(game);
	mlx_hook(game->win, 17, 0, free_img, game);
	mlx_hook(game->win, 2, 1, handle_moves, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n"
			"the arguments must look like : ./so_long <map PATH>\n",
			2);
		exit(1);
	}
	check_name(argv[1]);
	game = init();
	check_map(argv[1], game);
	start_game(game);
}
