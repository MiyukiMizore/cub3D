/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixel_in_minimap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:44:55 by mfusil            #+#    #+#             */
/*   Updated: 2023/05/30 22:20:30 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_textures_in_minimap(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	mlx_delete_image(game->mlx_ptr, game->minimap->img);
	game->minimap->img = mlx_new_image(game->mlx_ptr, 16, 16);
	ft_memset(game->minimap->img->pixels, 255, game->minimap->img->height
		* game->minimap->img->width * sizeof(int32_t));
	while (game->map[i] && i != ft_strlen_tab(game->map))
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1' && game->map[i][j] != '0')
				mlx_image_to_window(game->mlx_ptr, game->minimap->img,
					j * 16, i * 16);
			j++;
		}
		i++;
	}
	mlx_set_instance_depth(game->minimap->img->instances, 1);
}
