/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:54:29 by juzoanya          #+#    #+#             */
/*   Updated: 2022/06/07 20:17:04 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_line_count(char *argv[])
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		err_file_open();
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
		{
			free(str);
			break ;
		}
		else
			i++;
		free(str);
	}
	if (close(fd) == -1)
		err_file_close();
	return (i);
}

void	row_len(t_game *game, char **argv)
{
	int		i;
	int		j;
	int		fd;
	char	*str;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		err_file_open();
	while (i < game->map.row)
	{
		str = get_next_line(fd);
		j = 0;
		while (str[j] != '\0')
		{
			if (str[j] == '\n')
				break ;
			j++;
		}
		free(str);
		i++;
	}
	game->map.col = j;
	if (close(fd) == -1)
		err_file_close();
}

void	set_player_pos(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.row)
	{
		y = 0;
		while (y < game->map.col)
		{
			if (game->map.map[x][y] == 'P')
			{
				game->ply.pos_x = x;
				game->ply.pos_y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

static void	check_char_err(t_game *game, int p, int e)
{
	if (p != 1 || e != 1 || game->gems < 1)
	{
		ft_putendl_fd("Check that there is 1 player, 1 exit & 1 coin!", 1);
		destroy_map(game);
		free(game);
		exit(0);
	}
}

void	check_map_char(t_game *game)
{
	int	x;
	int	y;
	int	e;
	int	p;

	x = 0;
	e = 0;
	p = 0;
	while (x < game->map.row)
	{
		y = 0;
		while (y < game->map.col)
		{
			if (game->map.map[x][y] == 'P')
				p++;
			if (game->map.map[x][y] == 'E')
				e++;
			if (game->map.map[x][y] == 'C')
				game->gems++;
			y++;
		}
		x++;
	}
	check_char_err(game, p, e);
}
