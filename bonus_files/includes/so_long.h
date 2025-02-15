/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:49:39 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/15 19:49:23 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../get_next_line_/get_next_line.h"
# include "../../minilibx-linux/mlx.h"
# include "../../printf/ft_printf.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_map
{
	void	*mlx;
	void	*win;
	char	**map;
	int		rows;
	int		colums;
	int		coins;
	int		count_enemy;
	void	*player;
	void	*floor;
	void	*wall;
	void	*coin;
	void	*enemy;
	void	*exit;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
	int enemy_x;
    int enemy_y;
	int enemy_direction;
}			t_map;

int			check_file_name(char *str);
int			check_map(char *map, t_map *elm);
void		free_arr(char **p, int rows);
size_t		ft_strlen(const char *str);
int			flood_fill(t_map *map);
int			run_win(t_map *elm);
void		clean_up(t_map *elm);
int			file_to_ptr(t_map *elm);
int			check_walls(t_map *elm);
void		draw(t_map *map, int i, int j);
char		*ft_itoa(int n);
void		print_moves_in_window(t_map *map);

void initialize_enemy(t_map *elm);
void move_enemy(t_map *elm);
int game_loop(t_map *elm);
void	draw_map(t_map *map);

#endif
