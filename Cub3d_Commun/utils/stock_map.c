/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:52:35 by mfusil            #+#    #+#             */
/*   Updated: 2023/05/11 16:53:18 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	hauteur(char *map)
{
	int	fd;
	int	h;

	h = 0;
	fd = open(map, O_RDONLY);
	while (get_next_line(fd))
		h++;
	close(fd);
	return (h);
}

char	**stock_map(char *map, int i, int j)
{
	char	**newmap;
	char	*line;
	int		fd;

	fd = open(map, O_RDONLY);
	newmap = ft_calloc(1000, 1);
	line = get_next_line(fd);
	while (line)
	{
		newmap[i] = malloc(sizeof(char) * ft_strlen(line) + 1);
		while (line[j])
		{
			if (line[j] == '\n')
				break ;
			newmap[i][j] = line[j];
			printf("%c", newmap[i][j]);
			j++;
		}
		printf("\n");
		line = get_next_line(fd);
		i++;
	}
	newmap[i] = NULL;
	close(fd);
	return (newmap);
}
