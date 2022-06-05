/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:26:43 by juzoanya          #+#    #+#             */
/*   Updated: 2022/06/02 23:20:30 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, y * 32, x * 32);
}

void	check_exit_status(t_game *game, int x, int y)
{
	if (game->exit_state == 0)
		put_image(game, game->exit[0].img, x, y);
	else
		put_image(game, game->exit[1].img, x, y);
}

static void	select_img(t_game *game, int x, int y)
{
	if (!game->ply.die)
	{
		if (game->ply.side == 0)
			put_image(game, game->player[0].img, x, y);
		else if (game->ply.side == 1)
			put_image(game, game->player[1].img, x, y);
		else if (game->ply.side == 2)
			put_image(game, game->player[2].img, x, y);
		else if (game->ply.side == 3)
			put_image(game, game->player[3].img, x, y);
	}
	else
		put_image(game, game->player[4].img, x, y);
}

void	select_render(t_game *game, int x, int y)
{
	if (game->map.map[x][y] == '1')
		put_image(game, game->wall.img, x, y);
	else if (game->map.map[x][y] == 'C')
		put_image(game, game->coins.img, x, y);
	else if (game->map.map[x][y] == 'P')
		select_img(game, x, y);
	else if (game->map.map[x][y] == '0')
		put_image(game, game->space.img, x, y);
	else if (game->map.map[x][y] == 'S')
		put_image(game, game->snag[0].img, x, y);
	else if (game->map.map[x][y] == 'E')
		check_exit_status(game, x, y);
}

int	game_play(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.row)
	{
		y = 0;
		while (y < game->map.col)
		{
			select_render(game, x, y);
			print_moves(game);
			y++;
		}
		x++;
	}
	return (0);
}
