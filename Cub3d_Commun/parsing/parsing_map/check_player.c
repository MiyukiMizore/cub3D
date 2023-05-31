/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:10:19 by misimon           #+#    #+#             */
/*   Updated: 2023/05/11 15:59:58 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	caract_player(char c, t_parsing *direction)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (c == 'N')
			direction->player_direction = north;
		else if (c == 'S')
			direction->player_direction = south;
		else if (c == 'W')
			direction->player_direction = west;
		else
			direction->player_direction = east;
		return (true);
	}
	else
		return (false);
}

void	add_loc_player(t_parsing *parse, int y, int x)
{
	parse->x_pl = x;
	parse->y_pl = y;
}

int	player_loc(char **map, t_parsing *parse, int y)
{
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (caract_player(map[y][x], parse) == true
				&& parse->x_pl == 0 && parse->y_pl == 0)
			{
				add_loc_player(parse, y, x);
				map[y][x] = '0';
			}
			else if (caract_player(map[y][x], parse) == true
				&& parse->x_pl != 0 && parse->y_pl != 0)
				return (error_pl);
			x++;
		}
		x = 0;
		y++;
	}
	if (parse->y_pl == 0 && parse->x_pl == 0)
		return (error_pl);
	return (no_problem);
}
