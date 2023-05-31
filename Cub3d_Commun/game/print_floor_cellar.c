/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_floor_cellar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:24:23 by mfusil            #+#    #+#             */
/*   Updated: 2023/05/30 21:51:24 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_floor_cellar(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->height / 2)
	{
		x = -1;
		while (++x < game->width)
			mlx_put_pixel(game->third_d, x, y, game->collor_cellar);
	}
	while (++y < game->height - 1)
	{
		x = -1;
		while (++x < game->width)
			mlx_put_pixel(game->third_d, x, y, game->collor_floor);
	}
}
