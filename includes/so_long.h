/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:28:37 by juzoanya          #+#    #+#             */
/*   Updated: 2022/06/06 20:20:38 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __linux__
#include "../mlx/mlx_linux/mlx.h"
# elif __APPLE__
#include "../mlx/mlx_macos/mlx.h"
# endif
# include "get_next_line.h"
# include "../printf/ft_printf.h"

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_map
{
	char	**map;
	int		col;
	int		row;
}				t_map;

typedef struct s_image
{
	void	*img;
	int		x;
	int		y;
}				t_image;

typedef struct s_player
{
	void	*player;
	int		pos_x;
	int		pos_y;
	int		side;
	int		die;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_image		player[5];
	t_image		wall;
	t_image		space;
	t_image		coins;
	t_image		snag[5];
	t_image		exit[2];
	t_player	ply;
	int			exit_state;
	int			moves;
	int			gems;
	int			end;
}				t_game;

//error check functions
int		check_ext(char *str, char *ext);
void	valid_map(char *argv[]);
void	check_map_shape(t_game *game);
void	check_map_char(t_game *game);

//map fucntions
void	map_init(t_game *game, char **argv);
void	put_image(t_game *game, void *img, int x, int y);

//game play functions
int		game_play(t_game *game);
int		play_input(int keycode, t_game *game);
void	select_side(t_game *game, t_pos *pos, int n);
void	set_player_pos(t_game *game);
void	move_player(t_game *game, t_pos *pos);

//game ending functions
void	close_game(t_game *game);
void	destroy_image(t_game *game);
void	destroy_map(t_game *game);

//errors prototypes
void	err_file_open(void);
void	err_file_close(void);
void	err_extension(void);
void	err_map_char(void);
void	err_map_shape(void);

//helpers
int		get_line_count(char *argv[]);
int		player_active(t_game *game);
void	row_len(t_game *game, char **argv);
void	print_moves(t_game *game);

#endif