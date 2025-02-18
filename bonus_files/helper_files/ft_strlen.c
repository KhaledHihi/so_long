/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:17:15 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/18 21:08:15 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_size(t_map *elm)
{
	int		i;
	size_t	resolution;

	i = 1;
	resolution = ft_strlen(elm->map[0]);
	elm->colums = resolution - 1;
	while (elm->map[i])
	{
		if (resolution != ft_strlen(elm->map[i]))
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
