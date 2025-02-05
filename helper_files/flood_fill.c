/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:31:22 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/04 18:58:11 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_if_the_player(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == 'E')
				return 0;
			j++;
		}
		i++;
	}
	return (1);
}

void to_fill (t_map *map, char **the_map, int x, int y)
{
	if (x >= map->rows || y >= map->colums || x < 0 || y < 0)
		return ;
	if (the_map[x][y] != 'C' && the_map[x][y] != 'P' && the_map[x][y] != '0'
		&& the_map[x][y] != 'E')
		return ;
	the_map[x][y] = 'V';
	to_fill (map, the_map, x + 1, y);
	to_fill (map, the_map, x - 1, y);
	to_fill (map, the_map, x, y + 1);
	to_fill (map, the_map, x, y - 1);
}

int flood_fill(t_map *map)
{
	char **the_map;
	int (i), (j), (x), (y);

	i = -1;
	the_map = malloc(sizeof(char *) * map->rows + 1);
	while (++i < map->rows)
	{
		j = -1;
		the_map[i] = malloc(sizeof(char) * map->colums + 1);
		while(++j <= map->colums)
		{
			the_map[i][j] = map->map[i][j];
			if (the_map[i][j] == 'P')
			{
				y = j;
				x = i;
			}
		}
		the_map[i][j] = '\0';
	}
	the_map[i] = NULL;
	to_fill(map, the_map, x, y);
	if (check_if_the_player(the_map) == 0)
		return (free_arr(the_map, map->rows), 0);
	return (free_arr(the_map, map->rows), 1);
}
