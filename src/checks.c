/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 08:28:36 by juzoanya          #+#    #+#             */
/*   Updated: 2022/06/14 09:26:19 by juzoanya         ###   ########.fr       */
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
			err_map_char(1);
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
			err_map_char(1);
		if (!(is_valid_char(str[i])))
			err_map_char(0);
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

void	check_map_shape(t_game *game, char *argv[])
{
	char	*str;
	int		fd;
	int		i;
	int		x;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		err_file_open();
	x = 0;
	while (x++ < game->map.row)
	{
		i = 0;
		str = get_next_line(fd);
		while (str[i] != '\0')
		{
			if (str[i] == '\n')
				break ;
			i++;
		}
		free(str);
		if (i != game->map.col)
			err_map_shape();
	}
	if (close(fd) == -1)
		err_file_close();
}
