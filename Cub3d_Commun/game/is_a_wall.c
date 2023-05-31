/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:16:04 by mfusil            #+#    #+#             */
/*   Updated: 2023/05/30 18:19:38 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_a_wall(char **map, int x, int y)
{
	int	xx;
	int	yy;

	xx = floor(x / 16);
	yy = floor(y / 16);
	if (xx < 0 || yy < 0)
		return (true);
	else if (xx >= (int)ft_strlen(map[0]) - 1 || yy >= tab_len(map))
		return (true);
	else if (map[yy] && map[yy][xx] && map[yy][xx] == '1')
		return (true);
	return (false);
}
