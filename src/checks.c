/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 08:28:36 by juzoanya          #+#    #+#             */
/*   Updated: 2022/06/03 11:59:04 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'S')
		return (1);
	else if (c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

static void	check_walls(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	i -= 1;
	while (i >= 0)
	{
		if (str[i] != '1')
			err_map_char();
		i--;
	}
}

static void	check_valid_char(char *str)
{
	int	len;
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	len = i - 1;
	i = 0;
	while (str[i] != '\n')
	{
		if (str[0] != '1' || str[len] != '1')
			err_map_char();
		if (!(is_valid_char(str[i])))
			err_map_char();
		i++;
	}
}

void	valid_map(char *argv[])
{
	char	*str;
	int		fd;
	int		lines;
	int		i;

	lines = get_line_count(argv);
	i = lines;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		err_file_open();
	while (lines > 0)
	{
		str = get_next_line(fd);
		if (lines == i || lines == 1)
			check_walls(str);
		else
			check_valid_char(str);
		free(str);
		lines--;
	}
	if (close(fd) == -1)
		err_file_close();
}

void	check_map_shape(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.row)
	{
		y = 0;
		while (y < game->map.col)
			y++;
		if (y != game->map.col)
			err_map_shape();
		x++;
	}
}

// int	walls_check(t_game *game)
// {
// 	int	x;
// 	int	y;
// 	int	i;
// 	int	j;

// 	x = 0;
// 	i = game->map.col - 1;
// 	j = game->map.row - 1;
// 	while (x < game->map.row)
// 	{
// 		y = 0;
// 		while (y < game->map.col)
// 		{
// 			if (game->map.map[0][y] != '1' || game->map.map[x][0] != '1' ||
// 				game->map.map[x][i] != '1' || game->map.map[j][y] != '1')
// 				return (1);
// 			y++;
// 		}
// 		x++;
// 	}
// 	return (0);
// }

// int	char_check(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (x < game->map.row)
// 	{
// 		y = 0;
// 		while (y < game->map.col)
// 		{
// 			if (!is_valid_char(game->map.map[x][y]))
// 				return (1);
// 			y++;
// 		}
// 		x++;
// 	}
// 	return (0);
// }

// void	map_checks(t_game *game)
// {
// 	if (walls_check(game))
// 	{
// 		destroy_map(game);
// 		free(game);
// 		ft_printf("One or more entries is not a valid WALL char!\n");
// 		exit(0);
// 	}
// 	if (!check_map_shape(game))
// 	{
// 		destroy_map(game);
// 		free(game);
// 		ft_printf("Missaligned: Map is not a Rectangle!\n");
// 		exit(0);
// 	}
// 	if (char_check(game))
// 	{
// 		destroy_map(game);
// 		free(game);
// 		ft_printf("One or more entries is not a valid MAP char!\n");
// 		exit(0);
// 	}
// 	check_map_char(game);
// }
