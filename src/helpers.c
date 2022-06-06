/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:32:21 by juzoanya          #+#    #+#             */
/*   Updated: 2022/06/06 16:15:40 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ext(char *str, char *ext)
{
	int	len_str;
	int	len_ext;
	int	i;

	len_str = ft_strlen(str);
	len_ext = ft_strlen(ext);
	i = 0;
	while (len_ext > 0)
	{
		if (ext[--len_ext] == str[--len_str])
			i++;
		else
			return (0);
	}
	return (1);
}

void	print_moves(t_game *game)
{
	char	*str;
	char	*moves;

	moves = ft_itoa(game->moves);
	str = ft_strjoin("Moves: ", moves);
	free(moves);
	mlx_string_put(game->mlx, game->win, 25, 25, 0xFFFFFF, str);
	free(str);
	if (game->ply.die)
		mlx_string_put(game->mlx, game->win, 120, 25, 0xFFFFFF,
			"YOU LOSE! Press 'Esc' to Exit!");
	if (game->end)
		mlx_string_put(game->mlx, game->win, 120, 25, 0xFFFFFF,
			"YOU WIN! Press 'Esc' to Exit!");
}
