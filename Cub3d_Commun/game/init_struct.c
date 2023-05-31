/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:56:18 by mfusil            #+#    #+#             */
/*   Updated: 2023/05/30 21:51:05 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	max_distance(int map_width, int map_height)
{
	float	max_distance_x;
	float	max_distance_y;
	float	max_distance;

	max_distance_y = map_height * 16;
	max_distance_x = map_width * 16;
	max_distance = sqrt(max_distance_x * max_distance_x
			+ max_distance_y * max_distance_y);
	return (max_distance);
}

void	init_player(t_game *game, t_parsing *parse)
{
	game->player = ft_calloc(sizeof(t_player), 1);
	game->player->px = (parse->x_pl * 16) + 4;
	game->player->py = (parse->y_pl * 16) + 4;
	game->player->pdx = cos(game->player->pa) * 5;
	game->player->pdy = sin(game->player->pa) * 5;
	game->player->pa = 0;
}

void	init_image(t_game *game)
{
	game->image_player = ft_calloc(sizeof(t_image), 1);
	game->image_player->img = mlx_new_image(game->mlx_ptr, 4, 4);
	ft_memset(game->image_player->img->pixels, 255,
		game->image_player->img->height
		* game->image_player->img->width * sizeof(int32_t));
	if (!game->image_player->img)
		printf("Error: Creation of mlx_new_image failed\n");
	mlx_image_to_window(game->mlx_ptr, game->image_player->img,
		game->player->px, game->player->py);
}

void	init_texture(t_game *game, t_parsing *parse)
{
	int	i;

	i = -1;
	game->texture[0].texture = mlx_load_xpm42(parse->texture_no);
	game->texture[1].texture = mlx_load_xpm42(parse->texture_so);
	game->texture[2].texture = mlx_load_xpm42(parse->texture_ea);
	game->texture[3].texture = mlx_load_xpm42(parse->texture_we);
	while (++i < 4)
		if (!game->texture[i].texture)
			exit(1);
	game->texture[0].img = mlx_texture_to_image(game->mlx_ptr,
			&game->texture[0].texture->texture);
	game->texture[1].img = mlx_texture_to_image(game->mlx_ptr,
			&game->texture[1].texture->texture);
	game->texture[2].img = mlx_texture_to_image(game->mlx_ptr,
			&game->texture[2].texture->texture);
	game->texture[3].img = mlx_texture_to_image(game->mlx_ptr,
			&game->texture[3].texture->texture);
	i = -1;
	while (++i < 4)
		if (!game->texture[i].img)
			exit(1);
}

void	init_struct(t_game *game, char *arg, t_parsing *parse)
{
	(void)arg;
	game->projection = mlx_new_image(game->mlx_ptr, game->width, game->height);
	game->height = 960;
	game->width = 1280;
	game->map = parse->map;
	game->key = 0;
	game->mlx_ptr = mlx_init(game->width, game->height, "Cub3d", false);
	init_player(game, parse);
	init_image(game);
	game->minimap = ft_calloc(sizeof(t_image), 1);
	game->max_view_distance = max_distance((ft_strlen(game->map[0]) - 1),
			tab_len(game->map));
	init_texture(game, parse);
	init_render(game);
	init_draw_ns(game);
	init_draw_oe(game);
	game->collor_cellar = parse->color_c;
	game->collor_floor = parse->color_f;
}
