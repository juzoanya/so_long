/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_lin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:41:37 by juzoanya          #+#    #+#             */
/*   Updated: 2022/06/07 11:42:26 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(t_game *game)
{
	destroy_map(game);
	destroy_image(game);
	mlx_clear_window(game->mlx, game->win);
	mlx_loop_end(game->mlx);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}