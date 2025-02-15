/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:37:47 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/15 19:41:48 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void initialize_enemy(t_map *elm) {
    int i = 0;
    while (elm->map[i]) {
        int j = 0;
        while (elm->map[i][j]) {
            if (elm->map[i][j] == 'N') {
                elm->enemy_x = j;
                elm->enemy_y = i;
                elm->enemy_direction = 1; // Start by moving down
                return;
            }
            j++;
        }
        i++;
    }
}

void move_enemy(t_map *elm)
{
    int new_y = elm->enemy_y + elm->enemy_direction;

    // Check if the new position is valid (not a wall or outside the map)
    if (elm->map[new_y][elm->enemy_x] == '0' || elm->map[new_y][elm->enemy_x] == 'P') {
        elm->map[elm->enemy_y][elm->enemy_x] = '0'; // Clear old position
        elm->enemy_y = new_y;
        elm->map[new_y][elm->enemy_x] = 'N'; // Update new position
    } else {
        // Reverse direction if the enemy hits a wall or the edge
        elm->enemy_direction *= -1;
    }
}

int game_loop(t_map *elm)
{
    move_enemy(elm);
    draw_map(elm);
    return (0);
}
