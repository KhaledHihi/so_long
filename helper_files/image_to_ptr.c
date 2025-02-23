/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:14:09 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/20 15:54:07 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	file_to_ptr(t_map *elm)
{
	int (w), (h);
	elm->floor = mlx_xpm_file_to_image(elm->mlx, "textures/floor.xpm", &w, &h);
	elm->wall = mlx_xpm_file_to_image(elm->mlx, "textures/wall.xpm", &w, &h);
	elm->player = mlx_xpm_file_to_image(elm->mlx, "textures/player.xpm", &w,
			&h);
	elm->coin = mlx_xpm_file_to_image(elm->mlx, "textures/coin.xpm", &w, &h);
	elm->exit = mlx_xpm_file_to_image(elm->mlx, "textures/exit.xpm", &w, &h);
	if (!elm->floor || !elm->wall || !elm->player || !elm->coin || !elm->exit)
	{
		return (clean_up(elm), 0);
	}
	return (1);
}
