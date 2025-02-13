/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:21:16 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/07 18:30:40 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_map	elm;

	if (ac != 2 || !check_file_name(av[1]))
		return (perror("ERROR: file is not valid"), 1);
	if (check_map(av[1], &elm) == 0)
		return (perror("invalid map"), 1);
	run_win(&elm);
}
