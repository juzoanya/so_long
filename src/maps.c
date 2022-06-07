/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:43:40 by juzoanya          #+#    #+#             */
/*   Updated: 2022/06/07 11:43:44 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	push_to_array(t_game *game, int fd)
{
	int		i;
	int		x;
	int		y;
	char	*str;

	x = 0;
	while (x < game->map.row)
	{
		i = 0;
		y = 0;
		str = get_next_line(fd);
		while (y < game->map.col)
		{
			game->map.map[x][y] = str[i];
			i++;
			y++;
		}
		free(str);
		x++;
	}
}

void	map_init(t_game *game, char **argv)
{
	int		fd;
	int		i;

	game->gems = 0;
	game->map.row = get_line_count(argv);
	row_len(game, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		err_file_open();
	game->map.map = (char **)malloc(sizeof(game->map.map) * game->map.row);
	i = 0;
	while (i < game->map.row)
	{
		game->map.map[i] = (char *)malloc(sizeof(game->map.map[i])
				* game->map.col - 1);
		i++;
	}
	push_to_array(game, fd);
	if (close(fd) == -1)
		err_file_close();
	check_map_char(game);
	check_map_shape(game);
	set_player_pos(game);
}

// void	close_game(t_game *game)
// {
// 	destroy_map(game);
// 	destroy_image(game);
// 	mlx_clear_window(game->mlx, game->win);
// 	//if (OS_LINUX)
// 	//	mlx_loop_end(game->mlx);
// 	//game->loop.end = 1;
// 	mlx_destroy_window(game->mlx, game->win);
// 	//if (OS_LINUX)
// 	//	mlx_destroy_display(game->mlx);
// 	//free(game->mlx);
// 	exit(0);
// }
