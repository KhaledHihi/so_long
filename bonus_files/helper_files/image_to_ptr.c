/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:14:09 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/17 17:36:21 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	file_to_ptr(t_map *elm)
{
	int (w), (h);
	elm->floor = mlx_xpm_file_to_image(elm->mlx, "images/floor.xpm", &w, &h);
	elm->wall = mlx_xpm_file_to_image(elm->mlx, "images/wall.xpm", &w, &h);
	elm->player = mlx_xpm_file_to_image(elm->mlx, "images/player.xpm", &w, &h);
	elm->coin[0] = mlx_xpm_file_to_image(elm->mlx, "images/coin.xpm", &w, &h);
	elm->coin[1] = mlx_xpm_file_to_image(elm->mlx, "images/2.xpm", &w, &h);
	elm->coin[2] = mlx_xpm_file_to_image(elm->mlx, "images/3.xpm", &w, &h);
	elm->coin[3] = mlx_xpm_file_to_image(elm->mlx, "images/4.xpm", &w, &h);
	elm->coin[4] = mlx_xpm_file_to_image(elm->mlx, "images/5.xpm", &w, &h);
	elm->coin[5] = mlx_xpm_file_to_image(elm->mlx, "images/6.xpm", &w, &h);
	elm->coin[6] = mlx_xpm_file_to_image(elm->mlx, "images/7.xpm", &w, &h);
	elm->coin[7] = mlx_xpm_file_to_image(elm->mlx, "images/8.xpm", &w, &h);
	elm->coin[8] = mlx_xpm_file_to_image(elm->mlx, "images/9.xpm", &w, &h);
	elm->coin[9] = mlx_xpm_file_to_image(elm->mlx, "images/10.xpm", &w, &h);
	elm->enemy = mlx_xpm_file_to_image(elm->mlx, "images/enemy.xpm", &w, &h);
	elm->exit = mlx_xpm_file_to_image(elm->mlx, "images/exit.xpm", &w, &h);
	if (!elm->floor || !elm->wall || !elm->player || !elm->coin[0]
		|| !elm->coin[1] || !elm->coin[2] || !elm->coin[3] || !elm->coin[4]
		|| !elm->coin[5] || !elm->coin[6] || !elm->coin[6] || !elm->coin[7]
		|| !elm->coin[8] || !elm->enemy || !elm->coin[9] || !elm->exit)
	{
		return (clean_up(elm), 0);
	}
	return (1);
}
