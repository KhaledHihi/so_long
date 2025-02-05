/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:21:16 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/05 11:57:21 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int windows_close(t_map *elm)
{
	if (elm->win)
	{
		mlx_destroy_window(elm->mlx, elm->win);
		exit(0);
	}
	return 0;
}

int main(int ac, char **av)
{
	t_map	elm;

	elm.mlx = mlx_init();
	if (ac != 2 || !check_file_name(av[1]))
		return (perror("ERROR: file is not valid"), 1);
	if (check_map(av[1], &elm) == 0)
		return (perror("invalid map"), 1);
	elm.win = mlx_new_window(elm.mlx, elm.colums * 60, elm.rows * 60, "so_long");
	mlx_hook(elm.win, 17, 0, windows_close, &elm);
	mlx_loop(elm.mlx);
}
