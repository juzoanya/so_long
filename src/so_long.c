/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:27:13 by juzoanya          #+#    #+#             */
/*   Updated: 2022/06/07 20:12:49 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_close(t_game *game)
{
	close_game(game);
	return (0);
}

void	*image_file(void *mlx, char *str, int *x, int *y)
{
	return (mlx_xpm_file_to_image(mlx, str, x, y));
}

void	asset_init(t_game *game)
{
	void	*mlx;
	t_image	img;

	mlx = game->mlx;
	game->player[0].img = image_file(mlx, "./imgs/playerS.xpm", &img.x, &img.y);
	game->player[1].img = image_file(mlx, "./imgs/playerA.xpm", &img.x, &img.y);
	game->player[2].img = image_file(mlx, "./imgs/playerW.xpm", &img.x, &img.y);
	game->player[3].img = image_file(mlx, "./imgs/playerD.xpm", &img.x, &img.y);
	game->player[4].img = image_file(mlx, "./imgs/playero.xpm", &img.x, &img.y);
	game->snag[0].img = image_file(mlx, "./imgs/snag_0.xpm", &img.x, &img.y);
	game->snag[1].img = image_file(mlx, "./imgs/snag_1.xpm", &img.x, &img.y);
	game->snag[2].img = image_file(mlx, "./imgs/snag_2.xpm", &img.x, &img.y);
	game->snag[3].img = image_file(mlx, "./imgs/snag_3.xpm", &img.x, &img.y);
	game->snag[4].img = image_file(mlx, "./imgs/snag_4.xpm", &img.x, &img.y);
	game->exit[0].img = image_file(mlx, "./imgs/exit_x.xpm", &img.x, &img.y);
	game->exit[1].img = image_file(mlx, "./imgs/exit_o.xpm", &img.x, &img.y);
	game->wall.img = image_file(mlx, "./imgs/wall.xpm", &img.x, &img.y);
	game->space.img = image_file(mlx, "./imgs/grass.xpm", &img.x, &img.y);
	game->coins.img = image_file(mlx, "./imgs/coins.xpm", &img.x, &img.y);
}

void	game_init(t_game *game)
{
	t_image	image;

	image.x = 32;
	image.y = 32;
	game->moves = 0;
	game->exit_state = 0;
	game->end = 0;
	game->ply.side = 0;
	game->ply.die = 0;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, image.x * game->map.col,
			image.y * game->map.row, "so_long");
	asset_init(game);
	mlx_hook(game->win, 17, 0L, game_close, (void *)game);
	mlx_hook(game->win, 2, 1L << 0, play_input, (void *)game);
	print_moves(game);
	mlx_loop_hook(game->mlx, game_play, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc < 2)
	{
		ft_putendl_fd("Pass the location to Game map!", 1);
		exit(0);
	}
	if (!(check_ext(argv[1], ".ber")))
		err_extension();
	valid_map(argv);
	map_init(&game, argv);
	game_init(&game);
	exit(0);
}
