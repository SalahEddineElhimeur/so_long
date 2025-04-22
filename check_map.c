/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <sel-hime@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:45:45 by sel-hime          #+#    #+#             */
/*   Updated: 2025/04/20 18:01:22 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	double_free(char **pointer)
{
	int	i;

	if (!pointer)
		return ;
	i = 0;
	while (pointer[i])
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
}

void	free_all(t_game *game)
{
	double_free(game->copy);
	double_free(game->map);
	free(game);
}

static void	helper1(t_game *game, int fd, char *line)
{
	line = get_next_line(fd);
	if (!line)
		do_error(game, "Map is Empty\n", 0);
	game->height = 1;
	game->width = (int)ft_strlen(line);
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		if ((int)ft_strlen(line) != game->width)
		{
			free(line);
			get_next_line(-1);
			do_error(game, "Map is not valid\n", 0);
		}
		game->height++;
		free(line);
		line = get_next_line(fd);
	}
}

void	check_map(char *name, t_game *game)
{
	char	*line;
	int		fd;

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		perror(name);
		free(game);
		exit(1);
	}
	line = NULL;
	helper1(game, fd, line);
	close(fd);
	fd = open(name, O_RDONLY);
	helper2(game, fd, name);
	check_walls(game);
	read_map(game);
	helper3(game);
	close(fd);
}
