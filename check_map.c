/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:22:11 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/02 19:35:18 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"


int check_size(t_map *elm)
{
	int i;
	size_t resolution;

	i = 1;
	resolution = ft_strlen(elm->map[0]);
	while(elm->map[i])
	{
		if (resolution != ft_strlen(elm->map[i]))
			return (0);
		i++;
	}
	return (1);
}

// int check_regtangel(char *str)
// {
//     //check nafes size
// }
int check_valid_charcter(int fd, t_map *elm)
{
	int (i), (P), (E), (C);
	char *line;

	P = 0;
	E = 0;
	C = 0;
	elm->rows = 0;
	while((line = get_next_line(fd)))
	{
		i = -1;
		while(line[++i])
		{
			if(line[i] == 'P')
				P++;
			if(line[i] == 'E')
				E++;
			if(line[i] == 'C')
				C++;
		}
		elm->rows++;
		free (line);
	}
	if (P == 1 && C != 0 && E == 1)
		return (close(fd), 1);
	return (0);
}
// int flood_fill()
// {
//     // check 0
// }
char **read_map(int fd, t_map *data, char *file_name)
{
	int i;
	char **map;

	i = 0;
	fd = open (file_name, O_RDONLY);
	map = malloc(sizeof(char *) * (data->rows + 1));
	if (!map)
		return (NULL);
	while (data->rows > i)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}
void print_map(char **map, int rows)
{
    for(int i = 0; i < rows; i++)
    {
        printf("%s", map[i]);
    }
}

int check_map(char *file_name, t_map *elm)
{
	int fd;
	fd = open (file_name, O_RDONLY);
	if(!check_valid_charcter(fd, elm))
		return (0);
	elm->map = read_map(fd, elm, file_name);
	if (!check_size(elm))
		return (free_arr(elm->map, elm->rows), 0);
	free_arr(elm->map, elm->rows);
	return (1);
}
