/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:38:27 by mfusil            #+#    #+#             */
/*   Updated: 2023/05/30 20:11:41 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_render(t_game *game)
{
	game->render = ft_calloc(sizeof(t_render), 1);
	game->render->scale = 0.1;
	game->render->resolution_width = game->width;
	game->render->resolution_height = game->height;
	game->render->fov = M_PI / 6.0;
}

void	init_draw_ns(t_game *game)
{
	game->draw_ns = ft_calloc(sizeof(t_draw_ns), 1);
}

void	init_draw_oe(t_game *game)
{
	game->draw_oe = ft_calloc(sizeof(t_draw_oe), 1);
}
