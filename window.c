/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:10:58 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/06 23:30:12 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	draw_map(t_map *map)
{
    mlx_clear_window(map->mlx, map->win);
    int i = 0;
    while (map->map[i])
    {
        int j = 0;
        while (map->map[i][j])
        {
            if (map->map[i][j] == '0')
                mlx_put_image_to_window(map->mlx, map->win, map->floor, j * 32, i * 32);
            else if (map->map[i][j] == '1')
                mlx_put_image_to_window(map->mlx, map->win, map->wall, j * 32, i * 32);
            else if (map->map[i][j] == 'P')
                mlx_put_image_to_window(map->mlx, map->win, map->player, j * 32, i * 32);
            else if (map->map[i][j] == 'C')
                mlx_put_image_to_window(map->mlx, map->win, map->coin, j * 32, i * 32);
            else if (map->map[i][j] == 'E')
                mlx_put_image_to_window(map->mlx, map->win, map->exit, j * 32, i * 32);
            j++;
        }
        i++;
    }
}

void	move_player(t_map *elm, int move_x, int move_y)
{
    int new_x = elm->player_x + move_x;
    int new_y = elm->player_y + move_y;
    if (elm->map[new_y][new_x] == '1')
        return;
    if (elm->map[new_y][new_x] == 'C')
    {
        elm->collectibles--;
        elm->map[new_y][new_x] = '0';
    }
    if (elm->map[new_y][new_x] == 'E')
    {
        if (elm->collectibles == 0)
        {
            printf("You win!\n");
			free_arr(elm->map, elm->rows);
            exit(0);
        }
        else
            return;
    }
    elm->map[elm->player_y][elm->player_x] = '0';
    elm->player_x = new_x;
    elm->player_y = new_y;
    elm->map[new_y][new_x] = 'P';
    draw_map(elm);
}

int on_keypress(int key_code, t_map *elm)
{
	 static int moves;

    if (key_code == XK_Escape)
        exit(0);
    else if (key_code == XK_w || key_code == XK_Up)
    {
        move_player(elm, 0, -1);
        printf("moves: %d\n", ++moves);
    }
    else if (key_code == XK_s || key_code == XK_Down)
    {
        move_player(elm, 0, 1);
        printf("moves: %d\n", ++moves);
    }
    else if (key_code == XK_a || key_code == XK_Left)
    {
        move_player(elm, -1, 0);
        printf("moves: %d\n", ++moves);
    }
    else if (key_code == XK_d || key_code == XK_Right)
    {
        move_player(elm, 1, 0);
        printf("moves: %d\n", ++moves);
    }
    return (1);
}

int	run_win(t_map *elm)
{
	elm->mlx = mlx_init();
	if (!elm->mlx)
        return (0);
	elm->win = mlx_new_window(elm->mlx, elm->colums * 32, elm->rows * 32, "so_long");
	if (!elm->win)
        return (0);
	// mlx_hook(elm->win, 17, 0, &window_close, &elm);
	int w, h;
    elm->floor = mlx_xpm_file_to_image(elm->mlx, "images/floor.xpm", &w, &h);
    elm->wall = mlx_xpm_file_to_image(elm->mlx, "images/wall.xpm", &w, &h);
    elm->player = mlx_xpm_file_to_image(elm->mlx, "images/player.xpm", &w, &h);
    elm->coin = mlx_xpm_file_to_image(elm->mlx, "images/coin.xpm", &w, &h);
    elm->exit = mlx_xpm_file_to_image(elm->mlx, "images/exit.xpm", &w, &h);

    if (!elm->floor || !elm->wall || !elm->player || !elm->coin || !elm->exit)
		return (0);
	draw_map(elm);
	mlx_hook(elm->win, KeyPress, KeyPressMask, &on_keypress, elm);
	mlx_loop(elm->mlx);
	return (0);
}
