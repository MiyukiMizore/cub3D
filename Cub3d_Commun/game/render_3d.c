/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:21:20 by mfusil            #+#    #+#             */
/*   Updated: 2023/05/30 22:22:28 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	haaland_toty(t_game *game, int x)
{
	game->render->ray_angle = (game->player->pa - game->render->fov / 2.0)
		+ ((float)x / game->render->resolution_width) * game->render->fov;
	game->render->cos_ray = cos(game->render->ray_angle);
	game->render->sin_ray = sin(game->render->ray_angle);
	game->render->distance_to_wall = 0;
	game->render->hit_wall = false;
	while (!game->render->hit_wall
		&& game->render->distance_to_wall < game->max_view_distance)
	{
		game->render->distance_to_wall += 0.2;
		game->render->ray_x = game->player->px
			+ game->render->distance_to_wall * game->render->cos_ray;
		game->render->ray_y = game->player->py
			+ game->render->distance_to_wall * game->render->sin_ray;
		if (is_a_wall(game->map, game->render->ray_x, game->render->ray_y))
		{
			game->render->hit_wall = true;
			game->render->direction = 0;
			game->render->direction = what_face_of_wall(game->render->ray_x,
					game->render->ray_y, game);
		}
	}
}

void	messi_toty(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->render->resolution_width)
	{
		haaland_toty(game, x);
		game->render->distance_to_wall *= game->render->scale;
		game->render->distance_to_wall *= cos(game->player->pa
				- game->render->ray_angle);
		game->render->wall_height = (int)(game->render->resolution_height
				/ game->render->distance_to_wall) + 25;
		if (game->render->direction == 0 || game->render->direction == 1)
			draw_vertical_column_ns(game, x, (game->render->resolution_height
					- game->render->wall_height) / 2);
		else if (game->render->direction == 2 || game->render->direction == 3)
			draw_vertical_column_oe(game, x, (game->render->resolution_height
					- game->render->wall_height) / 2);
		else
			draw_vertical_column(game, x, (game->render->resolution_height
					- game->render->wall_height) / 2,
				color_pixel(150, 150, 150, 255));
		x++;
	}
}

void	render_3d(void *param)
{
	t_game		*game;

	game = (t_game *)param;
	mlx_delete_image(game->mlx_ptr, game->third_d);
	game->third_d = mlx_new_image(game->mlx_ptr, game->width, game->height);
	mlx_image_to_window(game->mlx_ptr, game->third_d, 0, 0);
	print_floor_cellar(game);
	messi_toty(game);
	mlx_set_instance_depth(game->third_d->instances, 1);
}
