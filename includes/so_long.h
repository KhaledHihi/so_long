/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:49:39 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/06 18:44:46 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../minilibx-linux/mlx.h"

typedef struct s_map
{
	void	*mlx;
	void	*win;
	char **map;
	int rows;
	int colums;
	int	coins;
	void    *player;
	void    *floor;
    void    *wall;
    void    *coin;
    void    *exit;
    int     player_x;
    int     player_y;
    int     collectibles;

}	t_map;

int	check_file_name(char *str);
int check_map(char *map, t_map *elm);
void	free_arr(char **p, int rows);
size_t	ft_strlen(const char *str);
int flood_fill(t_map *map);
int	run_win(t_map *elm);
#endif
