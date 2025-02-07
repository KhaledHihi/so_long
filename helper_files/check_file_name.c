/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:41:17 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/07 09:35:09 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_file_name(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 4 && str[len - 4] == '.' && str[len - 3] == 'b'
		&& str[len - 2] == 'e' && str[len - 1] == 'r')
		return (1);
	return (0);
}
