/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_in_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:26:19 by mfusil            #+#    #+#             */
/*   Updated: 2023/05/30 17:26:40 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_a_corner(int x, int y, t_game *game)
{
	if (!is_a_wall(game->map, x - 1, y) && !is_a_wall(game->map, x, y - 1))
		return (true);
	if (!is_a_wall(game->map, x + 1, y) && !is_a_wall(game->map, x, y - 1))
		return (true);
	if (!is_a_wall(game->map, x - 1, y) && !is_a_wall(game->map, x, y + 1))
		return (true);
	if (!is_a_wall(game->map, x + 1, y) && ! is_a_wall(game->map, x, y + 1))
		return (true);
	return (0);
}

int	what_face_of_wall(int x, int y, t_game *game)
{
	if (is_a_corner(x, y, game))
		return (4);
	else if (!is_a_wall(game->map, x, y - 1))
		return (0);
	else if (!is_a_wall(game->map, x, y + 1))
		return (1);
	else if (!is_a_wall(game->map, x - 1, y))
		return (2);
	else if (!is_a_wall(game->map, x + 1, y))
		return (3);
	return (5);
}

bool	player_collision(char **map, int x, int y)
{
	if (is_a_wall(map, x, y))
		return (true);
	if (is_a_wall(map, x + 3, y))
		return (true);
	if (is_a_wall(map, x, y + 3))
		return (true);
	if (is_a_wall(map, x + 3, y + 3))
		return (true);
	return (false);
}
