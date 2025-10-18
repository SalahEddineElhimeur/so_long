/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <sel-hime@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:45:25 by sel-hime          #+#    #+#             */
/*   Updated: 2025/10/18 00:57:52 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct s_data
{
	int		x;
	int		y;
	int		direction;
}			t_meta;
typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*player_img_up;
	void	*player_img_down;
	void	*player_img_right;
	void	*player_img_left;
	void	*collect_img;
	void	*wall_img;
	void	*exit_on_img;
	void	*floor_img;
	int		moves;
	int		height;
	int		player;
	int		collect;
	int		exit;
	int		width;
	int		exit_x;
	int		exit_y;
	char	**map;
	char	**copy;
	t_meta	data;
}			t_game;

void		check_name(char *name);
void		check_map(char *name, t_game *game);
void		read_map(t_game *game);
void		double_free(char **pointer);
void		free_all(t_game *game);
void		check_walls(t_game *game);
void		helper2(t_game *game, int fd, char *name);
void		helper3(t_game *game);
void		do_error(t_game *game, char *msg, int mode);
void		img_init(t_game *game);
int			free_img(t_game *game);
void		render_map(t_game *game);
void		check_new_position(t_game *game, int x, int y);
int			ft_printf(const char *format, ...);
void		msg(void);
#endif