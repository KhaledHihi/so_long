/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:43:17 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/15 19:14:09 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_moves_in_window(t_map *map)
{
	char	*moves_num;
	char	*moves_str;
	moves_num = ft_itoa(++map->moves);
	moves_str = ft_strjoin("Moves: ", moves_num);
	mlx_string_put(map->mlx, map->win, 20, 40, 0x000000, moves_str);
	free(moves_str);
	free(moves_num);
}
